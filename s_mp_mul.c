#include "tommath_private.h"
#ifdef S_MP_MUL_C
/* LibTomMath, multiple-precision integer library -- Tom St Denis */
/* SPDX-License-Identifier: Unlicense */

/* multiplies |a| * |b| and only computes upto digs digits of result
 * HAC pp. 595, Algorithm 14.12  Modified so you can control how
 * many digits of output are created.
 */
mp_err s_mp_mul(const mp_int *a, const mp_int *b, mp_int *c, int digs)
{
   mp_int  t;
   mp_err  err;
   int     pa, ix;
   mp_word m;

#ifdef MP_32BIT
   mp_digit u, v;
   volatile uint32_t op1, op2, op3, op4, op5, i;
   volatile bool ok_carry;
#else
   /* can we use the fast multiplier? */

   if ((digs < MP_WARRAY) &&
       (MP_MIN(a->used, b->used) < MP_MAX_COMBA)) {
      return s_mp_mul_comba(a, b, c, digs);
   }
#endif

   if ((err = mp_init_size(&t, digs)) != MP_OKAY) {
      return err;
   }
   mp_zero(&t);
   t.used = digs;


#ifdef STM32

	for(i = 0; i < a->used ; i++) {
		op1 = a->dp[i];
		op2 = &(t.dp[i]);
		op3 = &(b->dp[0]);
		if(b->used < digs - i) {
			op4 = b->used;
			ok_carry = true;
		}
		else {
			op4 = digs - i;
			ok_carry = false;
		}
		op5 = &(t.dp[i+op4]);
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
				"MOV %%r6, %4;"
				"CBZ %%r6, EXIT_1;"
				"STR %%r2, [%3];"
				"EXIT_1:"

				:
				: "r" (op1), "r" (op2), "r" (op3), "r" (op5), "r" (ok_carry)
				: "r1", "r2", "r3", "r4", "r6", "memory", "cc"

		);
	}

#else

   /* compute the digits of the product directly */
   pa = a->used;
   for (ix = 0; ix < pa; ix++) {
      int iy, pb;
      mp_digit k = 0;

      /* limit ourselves to making digs digits of output */
      pb = MP_MIN(b->used, digs - ix);

      /* compute the columns of the output and propagate the carry */
      for (iy = 0; iy < pb; iy++) {
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
         /* compute the column as a mp_word */
         m = (mp_word)t.dp[ix + iy] +
                     ((mp_word)a->dp[ix] * (mp_word)b->dp[iy]) +
                     (mp_word)k;

         /* the new column is the lower part of the result */
         t.dp[ix + iy] = (mp_digit)(m & (mp_word)MP_MASK);

         /* get the carry word from the result */
         k       = (mp_digit)(m >> (mp_word)MP_DIGIT_BIT);
#endif
      }
      /* set carry if it is placed below digs */
      if ((ix + iy) < digs) {
         t.dp[ix + pb] = k;
      }
   }


#endif

   mp_clamp(&t);
   mp_exch(&t, c);

   mp_clear(&t);
   return MP_OKAY;
}
#endif
