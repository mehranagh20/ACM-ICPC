import math

lo = [math.log10(2), ]
for i in range(3, 300001):
    lo.append(lo[-1] + math.log10(i))

while True:
    n = int(input())
    if not n:
        break
    n = 2 ** ((n - 1950) // 10 + 1)
    a, b, k = 0, 300000, 0
    le = math.log10(2) * n
    while a <= b:
        mi = (a + b) // 2
        res = lo[mi - 2]
        if res > le:
            b = mi - 1
        else:
            k = mi
            a = mi + 1

    print(k)

