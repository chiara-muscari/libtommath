/* LibTomMath, multiple-precision integer library -- Tom St Denis
 *
 * LibTomMath is library that provides for multiple-precision
 * integer arithmetic as well as number theoretic functionality.
 *
 * The library is designed directly after the MPI library by
 * Michael Fromberger but has been written from scratch with
 * additional optimizations in place.
 *
 * The library is free for all purposes without any express
 * guarantee it works.
 *
 * Tom St Denis, tomstdenis@iahu.ca, http://math.libtomcrypt.org
 */
#include <tommath.h>

/* divide by three (based on routine from MPI and the GMP manual) */
int
mp_div_3 (mp_int * a, mp_int *c, mp_digit * d)
{
  mp_int   q;
  mp_word  w, t;
  mp_digit b;
  int      res, ix;
  
  /* b = 2**DIGIT_BIT / 3 */
  b = (((mp_word)1) << ((mp_word)DIGIT_BIT)) / ((mp_word)3);

  if ((res = mp_init_size(&q, a->used)) != MP_OKAY) {
     return res;
  }
  
  q.used = a->used;
  q.sign = a->sign;
  w = 0;
  for (ix = a->used - 1; ix >= 0; ix--) {
     w = (w << ((mp_word)DIGIT_BIT)) | ((mp_word)a->dp[ix]);
     
     if (w >= 3) {
        t = (w * ((mp_word)b)) >> ((mp_word)DIGIT_BIT);
        w -= (t << ((mp_word)1)) + t;
        while (w >= 3) {
           t += 1;
           w -= 3;
        }
      } else {
        t = 0;
      }
      q.dp[ix] = t;
  }
  
  if (d != NULL) {
     *d = w;
  }
  
  if (c != NULL) {
     mp_clamp(&q);
     mp_exch(&q, c);
  }
  mp_clear(&q);
  
  return res;
}

