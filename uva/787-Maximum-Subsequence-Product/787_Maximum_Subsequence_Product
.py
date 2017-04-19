while True:
    a = []
    try:
        for i in input().split():
            if int(i) != -999999: a.append(int(i))
            else:
                ans = -100000000000000000
                for j in range(len(a)):
                    s = 1
                    for k in range(j, -1, -1):
                        s *= a[k]
                        if(s > ans): ans = s
                        if not s: break
                print(ans)
                break

    except: break
