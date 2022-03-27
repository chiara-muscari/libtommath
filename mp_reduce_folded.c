#include "tommath_private.h"

#ifdef MP_REDUCE_FOLDED_C
/* LibTomMath, multiple-precision integer library -- Tom St Denis */
/* SPDX-License-Identifier: Unlicense */

/* reduces x mod m, assumes 0 < x < m**2, mu is
 * precomputed via mp_reduce_setup.
 * From HAC pp.604 Algorithm 14.42
 */

mp_err mp_reduce_folded(mp_int *x, const mp_int *m, const mp_int *mu, mp_int *pi)
{

   mp_int  q; // x_p;
   mp_err  err;
   int     um = m->used;
   int s = um/2;
   int s_3 = 3*s;

   /* q = x */
   if ((err = mp_init_copy(&q, x)) != MP_OKAY) {
      return err;
   }


   /* q = x / b**(k * 3 / 2)  */
   mp_rshd(&q, s_3);

   /* q = q1 * pi */
  if ((err = mp_mul(&q, pi, &q)) != MP_OKAY) {
	 goto LBL_ERR;
  }

   /* x_p = x mod 2^(k * 3 / 2) + q */
   if ((err = mp_mod_2d(x, MP_DIGIT_BIT * s_3, x)) != MP_OKAY) {
      goto LBL_ERR;
   }

   if ((err = mp_add(x, &q, x)) != MP_OKAY) {
		 goto LBL_ERR;
	 }


   // From now on, it's like the standard reduce func

   mp_copy(x, &q);

   /*q = floor(x_p / 2**um)*/
   mp_rshd(&q, um);

   /* q = q * mu */

   //if ((err = mp_mul(&q, mu, &q)) != MP_OKAY) {
   if ((err = s_mp_mul_high(&q, mu, &q, s-1)) != MP_OKAY) {
		 goto LBL_ERR;
	 }

   //mp_mul_v32_highNdigs(&q, mu, &q, s-1);

   /* q = q / b**(k/2) */
   mp_rshd(&q, s);

   /* q = q * m mod b**(k+2), quick (no division) */
   if ((err = s_mp_mul(&q, m, &q, um + 2)) != MP_OKAY) {
      goto LBL_ERR;
   }

   if ((err = mp_mod_2d(x, MP_DIGIT_BIT * (um + 2), x)) != MP_OKAY) {
      goto LBL_ERR;
   }

   if(mp_cmp_mag(x, &q) == MP_LT) {
	   mp_grow(x, um+3);
	   x->dp[um+2] = 1;
	   x->used = um+3;
   }
   /* x = x - q */
   //mp_zero(x);
   if ((err = mp_sub(x, &q, x)) != MP_OKAY) {
      goto LBL_ERR;
   }

   /* Back off if it's too big */
   while (mp_cmp(x, m) != MP_LT) {
      if ((err = mp_sub(x, m, x)) != MP_OKAY) {
         goto LBL_ERR;
      }
   }

LBL_ERR:
   mp_clear(&q);
   //mp_clear(&x_p);

   return err;
}

#endif

