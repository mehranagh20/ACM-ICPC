memo = dict()

def solve(str):
    if len(str) == 1:
        return 1
    if not len(str):
        return 0

    if str in memo:
        return memo[str]
    memo[str] = 0

    memo[str] += (1 + solve(str[1:-1])) if str[0] == str[-1] else 0
    memo[str] += solve(str[1:]) + solve(str[:-1]) - solve(str[1:-1])
    return memo[str]

tc = int(input())
for i in range(tc):
    str = input()
    print(solve(str))
