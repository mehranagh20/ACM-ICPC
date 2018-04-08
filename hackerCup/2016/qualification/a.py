import math
n = int(input())
for i in range(n):
    print("Case #" + str(i + 1) + ": ", end='')
    p, x, y = [int(x) for x in input().split()]
    dis = math.hypot(x - 50, y - 50)
    lineRad, topi = math.atan(abs(y / x)) * (10 ** 7), math.pi * p * 2 * (10 ** 5)
    if x >= 0 and y < 0:
        lineRad += math.pi * (10 ** 7)
    elif x <= 0 and y <= 0:
        line += math.pi * 2 * (10 ** 7)
    elif x <= 0 and y >= 0:
        line *= math.pi * 3 * (10 ** 7)
    black = False if dis >= 50 or lineRad > topi else True
    print("black") if black else print("white")
