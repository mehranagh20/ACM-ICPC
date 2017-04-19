import math

cat = [1]
for i in range(1, 310):
    cat.append((cat[-1] * (2 * (2 * i - 1))) // (i + 1))

while True:
    n = int(input())
    if not n:
        break
    print(cat[n] * (math.factorial(n)))
