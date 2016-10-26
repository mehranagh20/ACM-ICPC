ignore = []
while True:
    s = input()
    if(s == "::"): break;
    ignore.append(s)
ls = []
while True:
    try:
        tmpL = []
        for s in input().split(): tmpL.append(s.lower())
        for i in range(len(tmpL)):
            if not tmpL[i] in ignore:
                tmpL[i] = tmpL[i].upper()
                ls.append((tmpL[i], (" ".join(tmpL))))
                tmpL[i] = tmpL[i].lower()

    except: break;
for el in sorted(ls, key= lambda i : i[0]): print(el[1])
