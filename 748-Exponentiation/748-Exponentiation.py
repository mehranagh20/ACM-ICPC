while True:
    try:
        base, power = input().split()
    except EOFError:
        break

    power = int(power)
    base = int(float(base) * 10000)
    pos = 4 * power
    ans = str(pow(base, power))[::-1]
    ans += (pos - len(ans)) * '0'
    ans = (ans[:pos] + '.' + ans[pos:])[::-1]
    print(ans.rstrip('0'))
