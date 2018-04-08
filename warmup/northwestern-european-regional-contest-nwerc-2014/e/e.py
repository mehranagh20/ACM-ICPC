from math import log, sqrt
import math

eps = 1e-6

def f2(n, c, p, v, s):
    f = s / v + s / (v * c)
    s = (n * (log(n, 2) ** (sqrt(2) * c))) / (p * 10 ** 9)
    return f + s

def func(n, c, p, v, s):
    f = s / (v * (c ** 2))
    s = (n * pow(log(n, 2), sqrt(2) * c) * log(log(n, 2)) * sqrt(2)) / (p * 10 ** 9)
    if abs(f - s) < eps:
        return 0
    elif f - s > eps:
        return 1
    else:
        return -1

while True:
    l = 0.0
    h = 50
    eps = 1e-9
    mid = 0
    try:
        n, p, s, v = [float(x) for x in input().split()]
    except:
        break
    while h - l >= eps:
        mid = (h + l) / 2
        k = func(n, mid, p, v, s)
        if k == 1:
            l = mid
        else:
            h = mid
    print(f2(n, mid, p, v, s), mid)
