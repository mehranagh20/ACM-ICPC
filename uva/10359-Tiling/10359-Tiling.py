memo = []

def func(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    if memo[n] != -1:
        return memo[n]

    memo[n] = func(n-1) + 2 * func(n-2)
    return memo[n]

while True:
    try:
        n = int(input())
    except EOFError:
        break

    memo = [-1] * 500
    print(func(n))
