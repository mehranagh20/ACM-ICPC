import math
n = int(input())
for i in range(1, n+1):
    str = input()
    ans = math.factorial(len(str))
    for j in range(65, 92):
        ans //= math.factorial(str.count(chr(j)))
    print("%s %d: %d" %("Data set", i, ans))
