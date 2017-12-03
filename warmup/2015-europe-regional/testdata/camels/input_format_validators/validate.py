#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
oneint = re.compile(integer + "\n")
manyint = re.compile("(" + integer + " )*" + integer + "\n")

line = stdin.readline()
assert oneint.match(line)
n = int(line)
assert 2 <= n <= 2 * 10 ** 5

for test in range(3):
    line = stdin.readline()
    assert manyint.match(line)
    a = list(map(int, line.split()))
    a.sort()
    assert a == list(range(1, n + 1))

assert len(stdin.readline()) == 0
sys.exit(42)
