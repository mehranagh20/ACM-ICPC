while True:
    try:
        a, b, = input().split()
    except EOFError:
        break
    baseA, baseB = [], []
    for i in range(2, 37):
        try:
            baseA.append((i, int(a, i)))
        except ValueError:
            pass
    for i in range(2, 37):
        try:
            baseB.append((i, int(b, i)))
        except ValueError:
            pass
    ans = (-1, -1)
    for i in baseA:
        for j in baseB:
            if j[1] == i[1]:
                ans = (i[0], j[0])
                break
        if ans[0] != -1:
            break
    if ans[0] != -1:
        print("%s (base %d) = %s (base %d)" %(a, ans[0], b, ans[1]))
    else:
        print("%s is not equal to %s in any base 2..36" %(a, b))
