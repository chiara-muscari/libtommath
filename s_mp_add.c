#include "tommath_private.h"
#ifdef S_MP_ADD_C
/* LibTomMath, multiple-precision integer library -- Tom St Denis */
/* SPDX-License-Identifier: Unlicense */

/* low level addition, based on HAC pp.594, Algorithm 14.7 */
mp_err s_mp_add(const mp_int *a, const mp_int *b, mp_int *c)
{
   int oldused, min, max, i;
#ifdef MP_32BIT
   mp_digit tmp, tmp0;
#endif
   mp_digit u;
   mp_err err;

#ifdef STM32
	volatile uint32_t base_address_op1, base_address_op2, base_address_res, limit_1, limit_2;
#endif

   /* find sizes, we let |a| <= |b| which means we have to sort
    * them.  "x" will point to the input with the most digits
    */

	if(a->used >= b->used) {
		max = a->used;
		min = b->used;
#ifdef STM32
		base_address_op1 = &(a->dp[0]);
		base_address_op2 = &(b->dp[0]);
		limit_1 = &(a->dp[b->used-1]);
		limit_2 = &(a->dp[a->used-1]);
#endif
	}
	else {
		max = b->used;
		min = a->used;
#ifdef STM32
		base_address_op1 = &(b->dp[0]);
		base_address_op2 = &(a->dp[0]);
		limit_1 = &(b->dp[a->used-1]);
		limit_2 = &(b->dp[b->used-1]);
#endif
	}

	/* init result */
	if ((err = mp_grow(c, max + 1)) != MP_OKAY) {
	  return err;
	}
	/* get old used digit count and set new one */
	oldused = c->used;
	c->used = max + 1;

#ifdef STM32
	base_address_res = &(c->dp[0]);
	__asm__ volatile (
					"MOV %%r3, %0;"
					"MOV %%r4, %1;"
					"MOV %%r5, %2;"
					"MOV %%r8, %3;"
					"MOV %%r9, %4;"

					"LDR %%r0, [%%r3];" // Load 1st operand
					"LDR %%r1, [%%r4];" // Load 2nd operand
					"ADDS %%r2, %%r0, %% r1 ;" // Perform the sum of the least significant digit
					"STR %%r2, [%%r5];" // Store the result

					"LOOP_1:" // Check for loop limitation
					"SUB %%r2, %%r8, %%r3;" // TODO: change this into sub 1 and check for 0
					"CBZ %%r2, LOOP_2;"

					"ADD %%r3, %%r3, $4;" // Increase the address
					"ADD %%r4, %%r4, $4;"
					"ADD %%r5, %%r5, $4;"

					"LDR %%r0, [%%r3];"
					"LDR %%r1, [%%r4];"
					"ADCS %%r2, %%r0, %%r1 ;" // Perform the sum, considering the carry from the previous one
					"STR %%r2, [%%r5];"
					"B LOOP_1;"

					"LOOP_2:" // Now just the carry propagation has to be computed
					"SUB %%r2, %%r9, %%r3;" // Check for end of loop
					"CBZ %%r2, EXIT_2;"
					"ADD %%r3, %%r3, $4;" // Increase the address
					"ADD %%r5, %%r5, $4;"
					"LDR %%r2, [%%r3];"
					"ADCS %%r2, $0 ;"
					"STR %%r2, [%%r5];"

					"B LOOP_2;"
					"EXIT_2:"
					"ADD %%r5, %%r5, $4;"
					"MOV %%r2, $0;"
					"ADCS %%r2, $0;"
					"STR %%r2, [%%r5];"


					:
					:"r" (base_address_op1), "r" (base_address_op2),
						 "r" (base_address_res), "r" (limit_1), "r" (limit_2)
					: "r0", "r1", "r2", "r3", "r4", "r5", "r8", "r9", "memory", "cc");
#else

   /* zero the carry */
   u = 0;
   for (i = 0; i < min; i++) {
#ifdef MP_32BIT
		tmp0 = a->dp[i] + b->dp[i];
		tmp = tmp0 + u;

		u = 0;
		if(tmp0 < a->dp[i]) {
			u++;
		}
		if(tmp < tmp0) {
			u++;
		}
		u = u%2;

		c->dp[i] = tmp;
#else
      /* Compute the sum at one digit, T[i] = A[i] + B[i] + U */
      c->dp[i] = a->dp[i] + b->dp[i] + u;

      /* U = carry bit of T[i] */
      u = c->dp[i] >> (mp_digit)MP_DIGIT_BIT;

      /* take away carry bit from T[i] */
      c->dp[i] &= MP_MASK;
#endif
   }

   /* now copy higher words if any, that is in A+B
    * if A or B has more digits add those in
    */
   if (min != max) {
      for (; i < max; i++) {
#ifdef	MP_32BIT
			tmp0 = a->dp[i] + u;
			if(tmp0 < a->dp[i]) {
				u = 1;
			}
			else {
				u = 0;
			}
			c->dp[i] = tmp0;
#else
         /* T[i] = A[i] + U */
         c->dp[i] = a->dp[i] + u;

         /* U = carry bit of T[i] */
         u = c->dp[i] >> (mp_digit)MP_DIGIT_BIT;

         /* take away carry bit from T[i] */
         c->dp[i] &= MP_MASK;
#endif
      }
   }

   /* add carry */
   c->dp[i] = u;

#endif

   /* clear digits above oldused */
   s_mp_zero_digs(c->dp + c->used, oldused - c->used);

   mp_clamp(c);
   return MP_OKAY;
}
#endif
