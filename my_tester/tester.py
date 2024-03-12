#!/usr/bin/env python3

import random
import subprocess

n_values = [100]
# n_values = [x for x in range(3, 101) if x == 3 or x == 5 or x % 10 == 0]
range_start = -500
range_end = 0

for n in n_values:
	outputs = []
	max_sequence = []
	min_sequence = []
	print(f"For n = {n}:")

	for _ in range(100):
		numbers = random.sample(range(range_start, range_end + 1), n)
		numbers_string = ' '.join(map(str, numbers))

		output = subprocess.check_output("./push_swap " + numbers_string, shell=True)
		output = output.decode()

		num_newlines = output.count('\n')
		outputs.append(num_newlines)

		if num_newlines == max(outputs):
			max_sequence = numbers
		if num_newlines == min(outputs):
			min_sequence = numbers

	averages = sum(outputs) / len(outputs)
	maximum = max(outputs)
	minimum = min(outputs)

	print("Average:", averages)
	print("Maximum:", maximum)
	print("Minimum:", minimum)
	print()
	print("Maximum Sequence:", *max_sequence)
	print()
	print("Minimum Sequence:", *min_sequence)
	print()
