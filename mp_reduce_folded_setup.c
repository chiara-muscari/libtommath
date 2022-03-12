#include "tommath_private.h"
#ifdef MP_REDUCE_FOLDED_SETUP_C
/* LibTomMath, multiple-precision integer library -- Tom St Denis */
/* SPDX-License-Identifier: Unlicense */

/* pre-calculate the value required for Barrett reduction
 * For a given modulus "b" it calulates the value required in "a"
 */
mp_err mp_reduce_folded_setup(mp_int *mu, mp_int *P_p, const mp_int *b)
{
   mp_err err;
   if ((err = mp_2expt(mu, (3 * b->used * MP_DIGIT_BIT) / 2)) != MP_OKAY) {
      return err;
   }
   return mp_div(mu, b, mu, P_p);
}
#endif
