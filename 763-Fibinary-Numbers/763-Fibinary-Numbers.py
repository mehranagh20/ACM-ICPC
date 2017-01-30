fib = [1, 2]
for i in range(101):
    fib.append(fib[i] + fib[i + 1])

tc = 0
while True:
    try:
        if tc:
            input()
        f, s, ss = input()[::-1], input()[::-1], 0
        if tc:
            print("")
        tc += 1
    except:
        break

    for i in range(len(f)):
        ss += int(f[i]) * fib[i]
    for i in range(len(s)):
        ss += int(s[i]) * fib[i]

    ans = ""
    for f in fib[::-1]:
        if f <= ss:
            ss -= f
            ans += '1'
        elif len(ans):
            ans += '0'
    if not ans:
        ans = '0'
    print(ans)
