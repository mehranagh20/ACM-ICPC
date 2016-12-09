while True:
    try:
        b, a = [int(x) for x in input().split()]
    except EOFError:
        break
    ans, tmp = 0, a
    for i in range(1, b + 1):
        ans += i * tmp
        tmp *= a

    print(ans)

