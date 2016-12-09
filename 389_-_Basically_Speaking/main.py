def numberToBase(n, b):
    if n == 0:
        return ['0']
    digits = []
    while n >= 1:
        digits.append(str(int(n % b)))
        if int(digits[-1]) > 9:
            digits[-1] = chr(55 + int(digits[-1]))
        n /= b
    return digits[::-1]

while True:
    try:
        a, b, c = input().split()
    except EOFError:
        break
    a, c = int(a, int(b)), int(c)
    ans = numberToBase(a, c)
    if len(ans) > 7:
        print("%7s" %("ERROR"))
    else:
        print ("%7s" %(''.join(ans)))
