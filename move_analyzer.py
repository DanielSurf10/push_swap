#!/usr/bin/env python3
"""
Push Swap move analyzer.
Generates random permutations, runs ./push_swap, and counts output lines.
"""

import random
import subprocess
import sys

PUSH_SWAP = "./push_swap"

TEST_SIZES = [round(10 * 1.5**i) for i in range(15)]


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
    # header = f"{'n':>6}  {'moves avg':>10}"
    header = f"quantidade,moves media"
    print(header)
    # print("-" * len(header))

    for size in TEST_SIZES:
        trials = 20 if size <= 10 else (10 if size <= 100 else 5)
        # trials = 100
        total = 0
        print(f"Teste - {size:4}: ", file=sys.stderr, end="", flush=True)
        for _ in range(trials):
            arr = list(range(1, size + 1))
            random.shuffle(arr)
            m = count_moves(arr)
            if m < 0:
                print(f"Error running push_swap for n={size}")
                sys.exit(1)
            total += m
            print(".", end='', file=sys.stderr, flush=True)
        print(file=sys.stderr, flush=True)
        avg = total / trials
        # print(f"{size:>6}  {avg:>10.0f}")
        print(f"{size},{int(avg)}")


if __name__ == "__main__":
    run_tests()
