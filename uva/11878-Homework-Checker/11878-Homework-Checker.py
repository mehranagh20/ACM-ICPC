corr = 0
while True:
    try:
        x, c = input().split('=')
    except:
        break
    if '-' in x:
        a, b = x.split('-')
        if str(int(a) - int(b)) == c:
            corr += 1
    else:
        a, b = x.split('+')
        if str(int(a) + int(b)) == c:
            corr += 1
print(corr)
