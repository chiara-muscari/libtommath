#include "tommath_private.h"
#ifdef S_MP_MUL_HIGH_C
/* LibTomMath, multiple-precision integer library -- Tom St Denis */
/* SPDX-License-Identifier: Unlicense */

/* multiplies |a| * |b| and does not compute the lower digs digits
 * [meant to get the higher part of the product]
 */
mp_err s_mp_mul_high(const mp_int *a, const mp_int *b, mp_int *c, int digs)
{
   mp_int   t;
   int      pa, pb, ix;
   mp_err   err;
   mp_word m;

#ifdef MP_32BIT
   mp_digit u, v;
   volatile uint32_t op1, op2, op3, op4, op5, op6, i;
#else

   /* can we use the fast multiplier? */
   if (MP_HAS(S_MP_MUL_HIGH_COMBA)
       && ((a->used + b->used + 1) < MP_WARRAY)
       && (MP_MIN(a->used, b->used) < MP_MAX_COMBA)) {
      return s_mp_mul_high_comba(a, b, c, digs);
   }
#endif

   if ((err = mp_init_size(&t, a->used + b->used + 1)) != MP_OKAY) {
      return err;
   }
   //mp_zero(&t);
   t.used = a->used + b->used + 1;

#ifdef STM32

	for(i = 0; i < a->used ; i++) {
		int start_y = digs - i;
		if (start_y < b->used) {
			op1 = a->dp[i];
			op2 = &(t.dp[digs]);
			op3 = &(b->dp[start_y]);
			op5 = &(t.dp[i+b->used]);
			__asm__ volatile (
					"MOV %%r4, %2;" // &(b->dp[0]);
					"MOV %%r1, %1;" // &(t.dp[i]);
					"MOV %%r3, $0;" // v

					"LOOP_0:"
					"MOV %%r2, $0;" // u, k

					"LDR %%r6, [%%r4];"
					"UMLAL %%r3, %%r2, %0, %%r6;"

					"LDR %%r6, [%%r1];"
					"ADDS %%r6, %%r6, %%r3;"
					"ADC %%r2, $0;" //k

					"STR %%r6, [%%r1];"
					"MOV %%r3, %%r2;"
					"ADD %%r4, %%r4, $4;"
					"ADD %%r1, %%r1, $4;"

					"SUB %%r6, %3, %%r1;"
					"CBZ %%r6, EXIT_0;"
					"B LOOP_0;"
					"EXIT_0:"
					"STR %%r2, [%3];"
					"EXIT_1:"

					:
					: "r" (op1), "r" (op2), "r" (op3), "r" (op5)
					: "r1", "r2", "r3", "r4", "r6", "memory", "cc"

			);
		}
    }

#else
   pa = a->used;
   pb = b->used;
   for (ix = 0; ix < pa; ix++) {
      int iy;
      mp_digit k = 0;

      for (iy = digs - ix; iy < pb; iy++) {
#ifdef MP_32BIT
			m = (mp_word)a->dp[ix] * (mp_word)b->dp[iy];
			u = m >> 32;
			v = m;
			v = v + k;
			if(v < k) // manage the potential carry coming from the previous addition
				u++;
			v = v + t.dp[ix+iy];
			if (v < t.dp[ix+iy])
				u++;
			t.dp[ix+iy] = v;
			k = u;
#else
         /* calculate the double precision result */
         m = (mp_word)t.dp[ix + iy] +
                     ((mp_word)a->dp[ix] * (mp_word)b->dp[iy]) +
                     (mp_word)k;

         /* get the lower part */
         t.dp[ix + iy] = (mp_digit)(m & (mp_word)MP_MASK);

         /* carry the carry */
         k       = (mp_digit)(m >> (mp_word)MP_DIGIT_BIT);
#endif
      }
      t.dp[ix + pb] = k;
   }
#endif
   mp_clamp(&t);
   mp_exch(&t, c);
   mp_clear(&t);
   return MP_OKAY;
}
#endif
