#include "tommath_private.h"
#ifdef MP_REDUCE_FOLDED_SETUP_C
/* LibTomMath, multiple-precision integer library -- Tom St Denis */
/* SPDX-License-Identifier: Unlicense */

/* pre-calculate the value required for Barrett reduction
 * For a given modulus "b" it calulates the value required in "a"
 */
mp_err mp_reduce_folded_setup(mp_int *mu, mp_int *P_p,  mp_int *b)
{
   mp_err err;
   int n = b->used;

   // If the number of digits is odd, consider it as the immediately superior even number
   if(b->used % 2 != 0)
	   n++;

   // Compute P'
   if ((err = mp_2expt(mu, (3 * n * MP_DIGIT_BIT) / 2)) != MP_OKAY) {
	  return err;
   }
   if ((err = mp_div(mu, b, NULL, P_p)) != MP_OKAY) {
	   return err;
   }
   // Compute mu
   if ((err = mp_2expt(mu, MP_DIGIT_BIT*(3 * n / 2 + 1))) != MP_OKAY) {
	  return err;
   }
   return mp_div(mu, b, mu, NULL);
}
#endif
