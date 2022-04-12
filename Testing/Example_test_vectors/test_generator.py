import random 
import os
import math
from bitstring import BitArray
import copy
import sys
from optparse import OptionParser


def find_number_of_N_bits_digits(n, N):
	# i is the number of 28 bits digits which compose the number n
	i = 1
	while(1):
		if(2**(N*i) > n):
			break
		i += 1
	return i

def c_array_repr_Nbits(a, name, n_n_bits_dig, N):
	name_t, n = name.split("_")
	number = N//4
	a = "{0:#0{1}x}".format(a,number*n_n_bits_dig+2)
	num = [a[i:i+number] for i in range(2, len(a), number)]
	string = f"uint32_t {name}[{n_n_bits_dig}] = " + "{"
	for dig in num:
		string += f"0x{dig}, "
	string = string[0:-2] + "};\n"
	return string

def gen_in_range_rand(n):
	'''
	Returns a random number of 2^n bits
	'''
	return random.randrange(2**(2**n-1), 2**(2**(n)))

def gen_in_range_pattern(pattern,  n):
	pattern_len = len(pattern)

	number = ""
	while len(number) < 2**n:
		number += pattern
	return BitArray(bin=number).uint
	 

def gen_number_by_digit_rand():
	# range from 256 to 2^13 bits
	n_dig1 = random.randrange(8, 256+1)
	string = f"uint_32t op1[{n_dig1}] = " + "{"
	for i in range(n_dig1):
		dig = random.randrange(0, 2**32)
		dig = "{0:#0{1}x}".format(dig, 2+8)
		string += f"{dig}, "
	string = string[0:-2] + "};"
	return string


def gen_jagged(name, l):
	jag_arr = f"uint32_t *{name}[] = "+"{"
	for i in range(l):
		jag_arr += f"{name}_{i}, "
	jag_arr = jag_arr[:-2]+"};\n\n"
	return jag_arr


def gen_operands_lists(log_total_num_bits_op1, log_total_num_bits_op2, num_bits_per_digit, operation, patterns, num_tests):
	op1 = []
	op2 = []
	res = []

	# 
	patterns_t = copy.deepcopy(patterns)
	for i in range (num_tests):	
		if len(patterns_t) > 0:	
			patt = patterns_t.pop()
			a = gen_in_range_pattern(patt, log_total_num_bits_op1)
			#print(a)

			b = gen_in_range_pattern(patt, log_total_num_bits_op2)
			#print(b)

		else:
			a = gen_in_range_rand(log_total_num_bits_op1)
			b = gen_in_range_rand(log_total_num_bits_op2)

		op1.append(a)
		op2.append(b)
		res.append(eval(f"a {operation} b"))

	return op1, op2, res


def gen_h_file(num_bits, operands, operation):

	OP1_NAME = "op1"
	OP2_NAME = "op2"
	RES_NAME = "res"

	num_tests = operands["NUM_TESTS"]

	file_name = f"test_vec_{num_bits}.h"
	path = operation+"/"
	path = os.path.join(path, file_name)
	fp = open(path, 'w')

	header = ""
	header += "#ifndef TEST_VEC_H_\n#define TEST_VEC_H_\n\n"
	header += f"int num_tests = {num_tests};\n\n"

	num_tests_tot = len(operands["RES"])
	ndigop1 = f"int nDigop1[{num_tests_tot}] = " + "{"
	ndigop2 = f"int nDigop2[{num_tests_tot}] = " + "{"
	ndigres = f"int nDigres[{num_tests_tot}] = " + "{"

	for i in range (num_tests):	
		a = operands["OP1"][i]
		b = operands["OP2"][i]
		c = operands["RES"][i]
		
		"""
		while(a > b**2):
			b = gen_in_range(r)
		"""

		n_N_bits_digits = find_number_of_N_bits_digits(a, num_bits)
		ndigop1 += f"{n_N_bits_digits}, "
		header += c_array_repr_Nbits(a, f"{OP1_NAME}_{i}", n_N_bits_digits, num_bits)

		n_N_bits_digits = find_number_of_N_bits_digits(b, num_bits)
		ndigop2 += f"{n_N_bits_digits}, "
		header += c_array_repr_Nbits(b, f"{OP2_NAME}_{i}", n_N_bits_digits, num_bits)

		n_N_bits_digits = find_number_of_N_bits_digits(c, num_bits)
		ndigres += f"{n_N_bits_digits}, "
		header += c_array_repr_Nbits(c, f"{RES_NAME}_{i}", n_N_bits_digits, num_bits)


	ndigop1 = ndigop1[:-2] + "};\n"
	ndigop2 = ndigop2[:-2] + "};\n"
	ndigres = ndigres[:-2] + "};\n"

	header += ndigop1
	header += ndigop2
	header += ndigres

	header += gen_jagged(OP1_NAME, num_tests)
	header += gen_jagged(OP2_NAME, num_tests)
	header += gen_jagged(RES_NAME, num_tests)

	header += "\n#endif"

	fp.write(header)
	fp.close()


def main(): 

	help_text = "Usage: python3 test_generator.py [options]\n\n" \
				"Operation supported addition, subtraction, multiplication, integer division, reduction\n\n" \
				"Example which outputs 100 tests for the sum operation, plus the random tests: " \
				"python3 test_generator.py -O add -n 100 -p"

	optparser = OptionParser(usage=help_text)
	optparser.add_option("-O", "--operation", dest="operation_string", default="reduction", help="Operation to test (add, sub, mul, div, reduction)")
	optparser.add_option("-n", "--number", type="int", dest="num_random_tests", default=10, help="Number of test vectors")
	optparser.add_option("-p", "--pattern", action="store_true", dest="pattern_choice", default=False, help="Include tests with patters")
	optparser.add_option("-N", "--log_bits", type="int", dest="bit_length_log", default=8, help="First operand will have 2**(bit_length_log+1) bits. Second operand will have 2**(bit_length_log) bits.")

	(options, args) = optparser.parse_args()
	operation_string = options.operation_string
	num_random_tests = options.num_random_tests
	pattern_choice = options.pattern_choice
	# Assume numbers between 2**8 and 2**13 bits, so keep the range in [8, 13]
	bit_length_log = options.bit_length_log

	operations_dict = {"add" : "+", "sub" : "-", "mul" : "*", "div" : "//", "reduction" : "%"}

	operation = operations_dict[operation_string]

	### Patterns:
	patterns = []

	# 10101010...
	patterns.append("10")

	# 1000000...10000000...
	patterns.append("1000")

	# 11001100...11001100...
	patterns.append("1100")	

	# 11001100...00110011...11001100...00110011...
	patterns.append("1100110000110011")	

	# 11111111...
	patterns.append("11")

	# 11111111...00000000...11111111...00000000...
	patterns.append("1111111100000000")	

	# 11100000...
	patterns.append("11100000")	

	# 11110000...
	patterns.append("11110000")	

	# 11111000...
	patterns.append("11111100")
	
	# 11111100...
	patterns.append("11111100")	

	# 11111110...
	patterns.append("11111110")	
	###

	###################### Generate the header file for the 28-bit per digit version
	n_bits_per_digit = 28

	num_tests_tot = 0

	op1_list = []
	op2_list = []
	res_list = []

	if pattern_choice == True:
	# Generate the tests with particular patterns
		num_tests = len(patterns)

		op1_tmp, op2_tmp, res_tmp = gen_operands_lists(bit_length_log+1, bit_length_log, n_bits_per_digit, operation, patterns, num_tests)
		op1_list.extend(op1_tmp)
		op2_list.extend(op2_tmp)
		res_list.extend(res_tmp)
		num_tests_tot += num_tests

	# Generate the random tests
	num_tests = num_random_tests
	op1_tmp, op2_tmp, res_tmp = gen_operands_lists(bit_length_log+1, bit_length_log, n_bits_per_digit, operation, [], num_tests)
	op1_list.extend(op1_tmp)
	op2_list.extend(op2_tmp)
	res_list.extend(res_tmp)
	num_tests_tot += num_tests

	operands = {"OP1" : op1_list, "OP2" : op2_list, "RES" : res_list, "NUM_TESTS" : num_tests_tot}

	gen_h_file(n_bits_per_digit, operands, operation_string)


	####################### Generate the header file for the 32-bit per digit version
	n_bits_per_digit = 32

	num_tests_tot = 0

	op1_list = []
	op2_list = []
	res_list = []

	if pattern_choice == True:
	# Generate the tests with particular patterns
		num_tests = len(patterns)

		op1_tmp, op2_tmp, res_tmp = gen_operands_lists(bit_length_log+1, bit_length_log, n_bits_per_digit, operation, patterns, num_tests)
		op1_list.extend(op1_tmp)
		op2_list.extend(op2_tmp)
		res_list.extend(res_tmp)
		num_tests_tot += num_tests

	# Generate the random tests
	num_tests = num_random_tests
	op1_tmp, op2_tmp, res_tmp = gen_operands_lists(bit_length_log+1, bit_length_log, n_bits_per_digit, operation, [], num_tests)
	op1_list.extend(op1_tmp)
	op2_list.extend(op2_tmp)
	res_list.extend(res_tmp)
	num_tests_tot += num_tests

	operands = {"OP1" : op1_list, "OP2" : op2_list, "RES" : res_list, "NUM_TESTS" : num_tests_tot}

	gen_h_file(n_bits_per_digit, operands, operation_string)

	

if __name__ == '__main__':
    main()