from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
twoint = re.compile(integer + " " + integer + "\n")

line = stdin.readline()
assert twoint.match(line)
[n, p] = list(map(int, line.split()))
assert 1 <= p <= n <= 200

for i in range(0, n):
    line = stdin.readline()
    assert twoint.match(line)
    a = list(map(int, line.split()))
    assert 0 <= a[0] < a[1] <= 100000

assert len(stdin.readline()) == 0

sys.exit(42)