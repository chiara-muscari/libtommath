#include "tommath_private.h"
#ifdef MP_ADD_C
/* LibTomMath, multiple-precision integer library -- Tom St Denis */
/* SPDX-License-Identifier: Unlicense */

/* high level addition (handles signs) */
mp_err mp_add(const mp_int *a, const mp_int *b, mp_int *c)
{
	if (MP_DIGIT_BIT == 32) {
	#ifdef STM32
		mp_err err = MP_OKAY;
		char msg[200];
		volatile uint32_t max_num_digits;
		volatile uint32_t base_address_op1, base_address_op2, base_address_res, limit_1, limit_2;

		if(a->used >= b->used) {
			base_address_op1 = &(a->dp[0]);
			base_address_op2 = &(b->dp[0]);
			max_num_digits = a->used;
			limit_1 = &(a->dp[b->used-1]);
			limit_2 = &(a->dp[a->used-1]);
		}
		else {
			base_address_op1 = &(b->dp[0]);
			base_address_op2 = &(a->dp[0]);
			max_num_digits = b->used;
			limit_1 = &(b->dp[a->used-1]);
			limit_2 = &(b->dp[b->used-1]);
		}

		if ((err = mp_grow(c, max_num_digits+1) != MP_OKAY)) {
			return err;
		}
		base_address_res = &(c->dp[0]);


		__asm__ volatile (
						"MOV %%r3, %0;"
						"MOV %%r4, %1;"
						"MOV %%r5, %2;"
						"MOV %%r8, %3;"
						"MOV %%r9, %4;"

						"LDR %%r0, [%%r3];"
						"LDR %%r1, [%%r4];"
						"ADDS %%r2, %%r0, %% r1 ;"
						"STR %%r2, [%%r5];"

						"LOOP_1:"
						"SUB %%r2, %%r8, %%r3;"
						"CBZ %%r2, LOOP_2;"

						"ADD %%r3, %%r3, $4;"
						"ADD %%r4, %%r4, $4;"
						"ADD %%r5, %%r5, $4;"

						"LDR %%r0, [%%r3];"
						"LDR %%r1, [%%r4];"
						"ADCS %%r2, %%r0, %%r1 ;"
						"STR %%r2, [%%r5];"
						"B LOOP_1;"

						"LOOP_2:"
						"SUB %%r2, %%r9, %%r3;"
						"CBZ %%r2, EXIT_2;"
						"ADD %%r3, %%r3, $4;"
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

		c->used = max_num_digits+1;
		mp_clamp(c);

		return err;

	#else

		mp_err err = MP_OKAY;
		short int a_is_max;
		int max_num_digits, min_num_digits;
		mp_digit tmp, tmp0;
		int i;
		mp_digit carry = 0;

		if(a->used >= b->used) {
			max_num_digits = a->used;
			min_num_digits = b->used;
			a_is_max = 1;
		}
		else {
			max_num_digits = b->used;
			min_num_digits = a->used;
			a_is_max = 0;
		}

		if ((err = mp_grow(c, max_num_digits+1) != MP_OKAY)) {
			return err;
		}

		for(i = 0; i < min_num_digits; i++) {
			tmp0 = a->dp[i] + b->dp[i];
			tmp = tmp0 + carry;

			carry = 0;
			if(tmp0 < a->dp[i]) {
				carry++;
			}
			if(tmp < tmp0) {
				carry++;
			}
			carry = carry%2;

			c->dp[i] = tmp;
		}

		if(a_is_max) {
			for( ; i < max_num_digits; i++) {
				tmp0 = a->dp[i] + carry;
				if(tmp0 < a->dp[i]) {
					carry = 1;
				}
				else {
					carry = 0;
				}
				c->dp[i] = tmp0;
			}
		}
		else {
			for( ; i < max_num_digits; i++) {
				tmp0 = b->dp[i] + carry;
				if(tmp0 < b->dp[i]) {
					carry = 1;
				}
				else {
					carry = 0;
				}
				c->dp[i] = tmp0;
			}
		}
		c->used = max_num_digits;
		c->dp[max_num_digits] = carry;
		if (carry != 0) {
			c->used++;
		}
		mp_clamp(c);

		return err;
	#endif
	}

	else {

	   /* handle two cases, not four */
	   if (a->sign == b->sign) {
		  /* both positive or both negative */
		  /* add their magnitudes, copy the sign */
		  c->sign = a->sign;
		  return s_mp_add(a, b, c);
	   }

	   /* one positive, the other negative */
	   /* subtract the one with the greater magnitude from */
	   /* the one of the lesser magnitude. The result gets */
	   /* the sign of the one with the greater magnitude. */
	   if (mp_cmp_mag(a, b) == MP_LT) {
		  MP_EXCH(const mp_int *, a, b);
	   }

	   c->sign = a->sign;
	   return s_mp_sub(a, b, c);
	}
}

#endif
