import math

ways = [[[-1 for k in range(600)] for j in range(21)] for i in range(21)]
dimensions, n = [4, 6, 8, 10, 12, 20], 6


def solve(k, summ):
    # print(k, summ)
    if summ < 0:
        return 0
    if k == 0:
        return 1 if summ == 0 else 0
    if ways[n][k][summ] != -1:
        return ways[n][k][summ]
    ways[n][k][summ] = 0
    for i in range(1, n + 1):
        ways[n][k][summ] += solve(k - 1, summ - i)
    return ways[n][k][summ]

# n = 8
# print(solve(1, 2))

n = int(input())
for i in range(1, n + 1):
    print("Case #" + str(i) + ": ", end='')
    need, k = [int(x) for x in input().split()]
    spells = [a.split('d') for a in input().split()]
    mx = 0.0
    for a, b in spells:
        a, b, c, des = int(a), b, 0, 0
        if '+' in b:
            c, b = -1 * int(b.split('+')[1]), int(b.split('+')[0])
        elif '-' in b:
            c, b = int(b.split('-')[1]), int(b.split('-')[0])
        b = int(b)
        nowneed = need + c
        nowneed = nowneed if nowneed >= 0 else 0
        allWays = b ** a
        n = b
        for i in range(nowneed, a * b + 1):
            # print(a, i, n)
            des += solve(a, i)
        prob = des / allWays
        mx = max(mx, prob)
    print("%6f" % mx)
