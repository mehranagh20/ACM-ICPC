def eval(str):
    if '(' not in str:
        return float(str)
    p, a, b = "", "", ""
    i = 1
    while str[i] == '.' or str[i].isdigit() or str[i] == '-':
        p += str[i]
        i += 1
    cur = 0
    i += 1
    if str[i] == '(':
        while i < len(str):
            if str[i] == '(':
                cur += 1
            elif str[i] == ')':
                cur -= 1
            a += str[i]
            i += 1
            if not cur:
                break
    else:
        while str[i] == '.' or str[i].isdigit() or str[i] == '-':
            a += str[i]
            i += 1
    i += 1
    b = str[i : - 1]
    pp, aa, bb = float(p), eval(a), eval(b)
    return pp * (aa + bb) + (1 - pp) * (aa - bb)


while True:
    str = input()
    if str == '()':
        break
    print("%.2f" % (eval(str)))
