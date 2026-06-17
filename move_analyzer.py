#!/usr/bin/env python3
"""
Push Swap move analyzer.
Generates random permutations, runs ./push_swap, and counts output lines.
"""

import random
import subprocess
import sys

PUSH_SWAP = "./push_swap"

TEST_SIZES = [
    3, 4, 5, 6, 7, 8, 9, 10,
    20, 30, 40, 50, 60, 70, 80, 90, 100,
    200, 300, 400, 500,
]


def count_moves(arr):
    inp = " ".join(str(x) for x in arr)
    res = subprocess.run(
        [PUSH_SWAP, *[str(x) for x in arr]],
        capture_output=True,
        text=True,
    )
    if res.returncode != 0:
        return -1
    output = res.stdout.strip()
    if output == "":
        return 0
    return len(output.splitlines())


def run_tests():
    header = f"{'n':>6}  {'moves avg':>10}"
    print(header)
    print("-" * len(header))

    for size in TEST_SIZES:
        trials = 20 if size <= 10 else (10 if size <= 100 else 5)
        total = 0
        for _ in range(trials):
            arr = list(range(1, size + 1))
            random.shuffle(arr)
            m = count_moves(arr)
            if m < 0:
                print(f"Error running push_swap for n={size}")
                sys.exit(1)
            total += m
        avg = total / trials
        print(f"{size:>6}  {avg:>10.0f}")


if __name__ == "__main__":
    run_tests()
