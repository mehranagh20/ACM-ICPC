tc = int(input())
for i in range(tc):
    cl = [x[1:-1] for x in input().split("|")]
    pos = False
    for i in cl:
        cur = True
        now = i.split("&")
        for j in now:
            if "~" not in j:
                if "~" + j in now:
                    cur = False
                    break
            else:
                if j[1:] in now:
                    cur = False
                    break
        if cur:
            pos = True
            break
    print("YES" if pos else "NO")
