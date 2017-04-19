import math
a, b = [int(x) for x in input().split()]
f, s = int(math.log(a, 2)) + 1, int(math.log(b, 2)) + 1
ans = 1
for i in range(f, s + 1):
    ans *= (i - 1)
print(ans)
