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
 * Tom St Denis, tomstdenis@iahu.ca, http://libtommath.iahu.ca
 */

#ifndef BN_H_
#define BN_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

/* some default configurations.  
 *
 * A "mp_digit" must be able to hold DIGIT_BIT + 1 bits 
 * A "mp_word" must be able to hold 2*DIGIT_BIT + 1 bits 
 *
 * At the very least a mp_digit must be able to hold 7 bits 
 * [any size beyond that is ok provided it overflow the data type]
 */
#ifdef MP_8BIT
   typedef unsigned char      mp_digit;
   typedef unsigned short     mp_word;
#elif defined(MP_16BIT)
   typedef unsigned short     mp_digit;
   typedef unsigned long      mp_word;
#else
   typedef unsigned long      mp_digit;
   typedef unsigned long long mp_word;
   #define DIGIT_BIT          28U
#endif  

#ifndef DIGIT_BIT
   #define DIGIT_BIT     ((CHAR_BIT * sizeof(mp_digit) - 1))  /* bits per digit */
#endif

#define MP_MASK       ((((mp_digit)1)<<((mp_digit)DIGIT_BIT))-((mp_digit)1))

/* equalities */
#define MP_LT        -1   /* less than */
#define MP_EQ         0   /* equal to */
#define MP_GT         1   /* greater than */

#define MP_ZPOS       0   /* positive integer */
#define MP_NEG        1   /* negative */

#define MP_OKAY       0   /* ok result */
#define MP_MEM        1   /* out of mem */
#define MP_VAL        2   /* invalid input */

#define KARATSUBA_MUL_CUTOFF    80                /* Min. number of digits before Karatsuba multiplication is used. */
#define KARATSUBA_SQR_CUTOFF    80                /* Min. number of digits before Karatsuba squaring is used. */

typedef struct  {
    int used, alloc, sign;
    mp_digit *dp;
} mp_int;

/* ---> init and deinit bignum functions <--- */

/* init a bignum */
int mp_init(mp_int *a);

/* free a bignum */
void mp_clear(mp_int *a);

/* shrink ram required for a bignum */
int mp_shrink(mp_int *a);

/* ---> Basic Manipulations <--- */

#define mp_iszero(a) (((a)->used == 0) ? 1 : 0)
#define mp_iseven(a) (((a)->used == 0 || (((a)->dp[0] & 1) == 0)) ? 1 : 0)
#define mp_isodd(a)  (((a)->used > 0 || (((a)->dp[0] & 1) == 1)) ? 1 : 0)

/* set to zero */
void mp_zero(mp_int *a);

/* set to a digit */
void mp_set(mp_int *a, mp_digit b);

/* set a 32-bit const */
int mp_set_int(mp_int *a, unsigned long b);

/* init to a given number of digits */
int mp_init_size(mp_int *a, int size);

/* copy, b = a */
int mp_copy(mp_int *a, mp_int *b);

/* inits and copies, a = b */
int mp_init_copy(mp_int *a, mp_int *b);

/* ---> digit manipulation <--- */

/* right shift by "b" digits */
void mp_rshd(mp_int *a, int b);

/* left shift by "b" digits */
int mp_lshd(mp_int *a, int b);

/* c = a / 2^b */
int  mp_div_2d(mp_int *a, int b, mp_int *c, mp_int *d);

/* b = a/2 */
int mp_div_2(mp_int *a, mp_int *b);

/* c = a * 2^b */
int mp_mul_2d(mp_int *a, int b, mp_int *c);

/* b = a*2 */
int mp_mul_2(mp_int *a, mp_int *b);

/* c = a mod 2^d */
int mp_mod_2d(mp_int *a, int b, mp_int *c);

/* ---> Basic arithmetic <--- */

/* compare a to b */
int mp_cmp(mp_int *a, mp_int *b);

/* c = a + b */
int mp_add(mp_int *a, mp_int *b, mp_int *c);

/* c = a - b */
int mp_sub(mp_int *a, mp_int *b, mp_int *c);

/* c = a * b */
int mp_mul(mp_int *a, mp_int *b, mp_int *c);

/* b = a^2 */
int mp_sqr(mp_int *a, mp_int *b);

/* a/b => cb + d == a */
int mp_div(mp_int *a, mp_int *b, mp_int *c, mp_int *d);

/* c == a mod b */
#define mp_mod(a, b, c) mp_div(a, b, NULL, c)

/* ---> single digit functions <--- */

/* compare against a single digit */
int mp_cmp_d(mp_int *a, mp_digit b);

/* c = a + b */
int mp_add_d(mp_int *a, mp_digit b, mp_int *c);

/* c = a - b */
int mp_sub_d(mp_int *a, mp_digit b, mp_int *c);

/* c = a * b */
int mp_mul_d(mp_int *a, mp_digit b, mp_int *c);

/* a/b => cb + d == a */
int mp_div_d(mp_int *a, mp_digit b, mp_int *c, mp_digit *d);

/* c = a mod b */
#define mp_mod_d(a,b,c) mp_div_d(a, b, NULL, c)

/* ---> number theory <--- */

/* d = a + b (mod c) */
int mp_addmod(mp_int *a, mp_int *b, mp_int *c, mp_int *d);

/* d = a - b (mod c) */
int mp_submod(mp_int *a, mp_int *b, mp_int *c, mp_int *d);

/* d = a * b (mod c) */
int mp_mulmod(mp_int *a, mp_int *b, mp_int *c, mp_int *d);

/* c = a * a (mod b) */
int mp_sqrmod(mp_int *a, mp_int *b, mp_int *c);

/* c = 1/a (mod b) */
int mp_invmod(mp_int *a, mp_int *b, mp_int *c);

/* c = (a, b) */
int mp_gcd(mp_int *a, mp_int *b, mp_int *c);

/* c = [a, b] or (a*b)/(a, b) */
int mp_lcm(mp_int *a, mp_int *b, mp_int *c);

/* used to setup the Barrett reduction for a given modulus b */
int mp_reduce_setup(mp_int *a, mp_int *b);

/* Barrett Reduction, computes a (mod b) with a precomputed value c  */
int mp_reduce(mp_int *a, mp_int *b, mp_int *c);
 
/* d = a^b (mod c) */
int mp_exptmod(mp_int *a, mp_int *b, mp_int *c, mp_int *d);

/* ---> radix conversion <--- */

int mp_count_bits(mp_int *a);

int mp_unsigned_bin_size(mp_int *a);
int mp_read_unsigned_bin(mp_int *a, unsigned char *b, int c);
int mp_to_unsigned_bin(mp_int *a, unsigned char *b);

int mp_signed_bin_size(mp_int *a);
int mp_read_signed_bin(mp_int *a, unsigned char *b, int c);
int mp_to_signed_bin(mp_int *a, unsigned char *b);

int mp_read_radix(mp_int *a, unsigned char *str, int radix);
int mp_toradix(mp_int *a, unsigned char *str, int radix);

#define mp_tobinary(M, S)  mp_toradix((M), (S), 2)
#define mp_tooctal(M, S)   mp_toradix((M), (S), 8)
#define mp_todecimal(M, S) mp_toradix((M), (S), 10)
#define mp_tohex(M, S)     mp_toradix((M), (S), 16)

#endif

