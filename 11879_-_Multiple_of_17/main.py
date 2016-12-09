while True:
    n = input()
    if n == '0':
        break
    if len(n) < 2:
        a, b = 0, int(n)
    else:
        a, b = int(n[:-1]), int(n[-1])

    a -= b * 5
    if a % 17 == 0:
        print(1)
    else:
        print(0)
