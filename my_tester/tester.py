#!/usr/bin/env python3

import random
import subprocess

n_values = [5000]
# n_values = [x for x in range(3, 101) if x == 3 or x == 5 or x % 10 == 0]
range_start = 0
range_end = 5000

for n in n_values:
	outputs = []
	print(f"For n = {n}:")

	for _ in range(1000):
		numbers = random.sample(range(range_start, range_end + 1), n)
		numbers_string = ' '.join(map(str, numbers))

		output = subprocess.check_output("./push_swap " + numbers_string, shell=True)
		output = output.decode()

		num_newlines = output.count('\n')
		outputs.append(num_newlines)

	averages = sum(outputs) / len(outputs)
	maximum = max(outputs)
	minimum = min(outputs)

	print("Average:", averages)
	print("Maximum:", maximum)
	print("Minimum:", minimum)
	print()
