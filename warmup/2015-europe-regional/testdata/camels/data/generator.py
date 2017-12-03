#!/usr/bin/env python3
import random
from sys import stdin

s = stdin.readline().strip().split()
if s[0] == "exactly":
    n = int(s[1])
else:
    n = random.randint(int(s[1]), int(s[2]))

print(n)

a = [i+1 for i in range(n)]
b = [i+1 for i in range(n)]
c = [i+1 for i in range(n)]
random.shuffle(a)
random.shuffle(b)
random.shuffle(c)

for x in [a, b, c]:
    print(" ".join(map(str, x)))
