#include "tommath_private.h"
#ifdef MP_MUL_C
/* LibTomMath, multiple-precision integer library -- Tom St Denis */
/* SPDX-License-Identifier: Unlicense */

/* high level multiplication (handles sign) */
mp_err mp_mul(const mp_int *a, const mp_int *b, mp_int *c)
{
	if (MP_DIGIT_BIT == 32) {
#ifdef STM32
		mp_err err = MP_OKAY;
		mp_int q;
		mp_digit k, u, v;
		uint64_t m;
		volatile uint32_t op1, op2, op3, op4, op5, i;

		mp_init(&q);
		if ((err = mp_grow(&q, a->used + b->used) != MP_OKAY)) {
			return err;
		}
		mp_zero(&q);
		q.used = a->used + b->used;

		for(i = 0; i < a->used ; i++) {
			op1 = a->dp[i];
			op2 = &(q.dp[i]);
			op3 = &(b->dp[0]);
			op4 = b->used;
			op5 = &(q.dp[i+b->used]);
			__asm__ volatile (
					"MOV %%r4, %2;" // op3
					"MOV %%r5, $0;" // j index
					"MOV %%r8, %4;"
					"MOV %%r0, %0;" // op1
					"MOV %%r1, %1;" // op2
					"MOV %%r3, $0;" // v

					"LOOP_0:"
					"MOV %%r2, $0;" // u, k

					"LDR %%r6, [%%r4, %%r5];"
					"UMLAL %%r3, %%r2, %%r0, %%r6;"

					"LDR %%r6, [%%r1, %%r5];"
					"ADDS %%r6, %%r6, %%r3;"
					"ADC %%r2, $0;" //k
					"STR %%r6, [%%r1, %%r5];"
					"MOV %%r3, %%r2;"
					"ADD %%r5, %%r5, $4;"

					"LSRS %%r6, %%r5, $2;"
					"SUB %%r6, %3, %%r6;"
					"CBZ %%r6, EXIT_0;"
					"B LOOP_0;"
					"EXIT_0:"
					"STR %%r2, [%%r8];"
					:
					: "r" (op1), "r" (op2), "r" (op3), "r" (op4), "r" (op5)
					: "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r8", "memory", "cc"

			);
			// WARNING ADD THIS above
			//q.dp[i+b->used] = k;
		}
		mp_clamp(&q);
		mp_copy(&q, c);
		mp_clear(&q);

		return err;
#else
		mp_err err = MP_OKAY;
		mp_int q;
		mp_digit k, u, v;
		uint64_t m;

		mp_init(&q);
		if ((err = mp_grow(&q, a->used + b->used) != MP_OKAY)) {
			return err;
		}
		mp_zero(&q);
		q.used = a->used + b->used;

		for(int i = 0; i < a->used ; i++) {
			k = 0;
			for(int j = 0; j < b->used; j++) {
				m = (uint64_t)a->dp[i] * (uint64_t)b->dp[j];
				u = m >> 32;
				v = m;
				v = v + k;
				if(v < k) // manage the potential carry coming from the previous addition
					u++;
				v = v + q.dp[i+j];
				if (v < q.dp[i+j])
					u++;
				q.dp[i+j] = v;
				k = u;
			}
			q.dp[i+b->used] = k;
		}
		mp_clamp(&q);
		mp_copy(&q, c);
		mp_clear(&q);

		return err;
#endif
	}
   mp_err err;
   int min = MP_MIN(a->used, b->used),
       max = MP_MAX(a->used, b->used),
       digs = a->used + b->used + 1;
   bool neg = (a->sign != b->sign);

   if ((a == b) &&
       MP_HAS(S_MP_SQR_TOOM) && /* use Toom-Cook? */
       (a->used >= MP_SQR_TOOM_CUTOFF)) {
      err = s_mp_sqr_toom(a, c);
   } else if ((a == b) &&
              MP_HAS(S_MP_SQR_KARATSUBA) &&  /* Karatsuba? */
              (a->used >= MP_SQR_KARATSUBA_CUTOFF)) {
      err = s_mp_sqr_karatsuba(a, c);
   } else if ((a == b) &&
              MP_HAS(S_MP_SQR_COMBA) && /* can we use the fast comba multiplier? */
              (((a->used * 2) + 1) < MP_WARRAY) &&
              (a->used < (MP_MAX_COMBA / 2))) {
      err = s_mp_sqr_comba(a, c);
   } else if ((a == b) &&
              MP_HAS(S_MP_SQR)) {
      err = s_mp_sqr(a, c);
   } else if (MP_HAS(S_MP_MUL_BALANCE) &&
              /* Check sizes. The smaller one needs to be larger than the Karatsuba cut-off.
               * The bigger one needs to be at least about one MP_MUL_KARATSUBA_CUTOFF bigger
               * to make some sense, but it depends on architecture, OS, position of the
               * stars... so YMMV.
               * Using it to cut the input into slices small enough for s_mp_mul_comba
               * was actually slower on the author's machine, but YMMV.
               */
              (min >= MP_MUL_KARATSUBA_CUTOFF) &&
              ((max / 2) >= MP_MUL_KARATSUBA_CUTOFF) &&
              /* Not much effect was observed below a ratio of 1:2, but again: YMMV. */
              (max >= (2 * min))) {
      err = s_mp_mul_balance(a,b,c);
   } else if (MP_HAS(S_MP_MUL_TOOM) &&
              (min >= MP_MUL_TOOM_CUTOFF)) {
      err = s_mp_mul_toom(a, b, c);
   } else if (MP_HAS(S_MP_MUL_KARATSUBA) &&
              (min >= MP_MUL_KARATSUBA_CUTOFF)) {
      err = s_mp_mul_karatsuba(a, b, c);
   } else if (MP_HAS(S_MP_MUL_COMBA) &&
              /* can we use the fast multiplier?
               *
               * The fast multiplier can be used if the output will
               * have less than MP_WARRAY digits and the number of
               * digits won't affect carry propagation
               */
              (digs < MP_WARRAY) &&
              (min <= MP_MAX_COMBA)) {
      err = s_mp_mul_comba(a, b, c, digs);
   } else if (MP_HAS(S_MP_MUL)) {
      err = s_mp_mul(a, b, c, digs);
   } else {
      err = MP_VAL;
   }
   c->sign = ((c->used > 0) && neg) ? MP_NEG : MP_ZPOS;
   return err;
}
#endif
