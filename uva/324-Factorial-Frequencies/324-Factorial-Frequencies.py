import math
f = math.factorial
while True:
    n = int(input())
    if not n:
        break
    fac = str(f(n))
    ans = [fac.count(str(i)) for i in range(10)]
    print("%d! --\n   (%d)%5s" % (n, 0, ans[0]), end='')
    for i in range(1, 5):
        print("    (%d)%5s" % (i, ans[i]), end='')
    print('')
    print("   (%d)%5s" % (5, ans[5]), end ='')
    for i in range(6, 10):
        print("    (%d)%5s" % (i, ans[i]), end='')
    print('')
