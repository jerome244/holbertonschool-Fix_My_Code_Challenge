#!/usr/bin/python3
""" FizzBuzz
"""
import sys


def fizzbuzz(n):
    """
    Print numbers from 1 to n separated by a space.
    - Multiples of 3  -> "Fizz"
    - Multiples of 5  -> "Buzz"
    - Multiples of 15 -> "FizzBuzz"
    """
    if n < 1:
        return

    out = []
    for i in range(1, n + 1):
        if i % 15 == 0:
            out.append("FizzBuzz")
        elif i % 3 == 0:
            out.append("Fizz")
        elif i % 5 == 0:
            out.append("Buzz")
        else:
            out.append(str(i))
    print(" ".join(out))


if __name__ == "__main__":
    if len(sys.argv) <= 1:
        print("Missing number")
        print("Usage: ./0-fizzbuzz.py <number>")
        print("Example: ./0-fizzbuzz.py 50")
        sys.exit(1)

    number = int(sys.argv[1])
    fizzbuzz(number)
