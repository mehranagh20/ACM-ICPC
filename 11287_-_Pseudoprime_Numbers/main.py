import random


def miller_rabin(n, k):
    if n == 2 or n == 3:
        return True
    if n % 2 == 0:
        return False
    r, s = 0, n - 1
    while s % 2 == 0:
        r += 1
        s //= 2
    for _ in range(k):
        a = random.randrange(2, n - 1)
        x = pow(a, s, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True


def fast_power(a, n, m): # (a ^ n) % m
    """
    This function assumes that n >= 0
    """
    result = 1
    value = a
    power = n
    while power > 0:
        if power % 2 == 1:
            result = result * value
            result %= m
        value = value * value
        value %= m
        power = power//2
    return result

while True:
    a, b = [int(x) for x in input().split()]
    if a == b == 0:
        break
    if fast_power(b, a) == b and not miller_rabin(a, 30):
        print("yes")
    else:
        print("no")