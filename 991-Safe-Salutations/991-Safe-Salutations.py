import math
f, tc = math.factorial, 0
cat = []
for i in range(11):
    cat.append(f(i * 2) // (f(i + 1) * f(i)))
print(cat)
while True:
    try:
        n = int(input())
        if tc:
            print()
        tc += 1
        print(cat[n])
    except:
        break
