tc = 0
while True:
    tc += 1
    n = [int(a) for a in input().split()]
    if n[0] == 0 and n[1] == 0:
        break
    ans = 0
    for i in range(n[0]):
        ans += int(input())
    print("Bill #%d costs %d: each friend should pay %d\n" %(tc, ans, ans // n[1]))
