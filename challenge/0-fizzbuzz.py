#!/usr/bin/python3
import sys

if __name__ == "__main__":
    n = int(sys.argv[1]) if len(sys.argv) > 1 else 100

    tokens = []
    for i in range(1, n + 1):
        if i % 15 == 0:
            tokens.append("FizzBuzz")
        elif i % 3 == 0:
            tokens.append("Fizz")
        elif i % 5 == 0:
            tokens.append("Buzz")
        else:
            tokens.append(str(i))

    print(" ".join(tokens))
