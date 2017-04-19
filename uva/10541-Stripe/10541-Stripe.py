memo, s, n, k = list(), list(), -1, -1


def solve(id, w):
    if id == k:
        return 1 if w <= n + 2 else 0
    if w > n:
        return 0
    if memo[id][w] != -1:
        return memo[id][w]
    memo[id][w] = 0
    for i in range(n - w + 1):
        memo[id][w] += solve(id + 1, w + s[id] + i + 1)
    return memo[id][w]

tc = int(input())
for i in range(tc):
    l = [int(x) for x in input().split()]
    n, k, s = l[0], l[1], l[2:]
    memo = [[-1 for i in range(n + 5)] for j in range(k + 5)]
    print(solve(0, 1))
