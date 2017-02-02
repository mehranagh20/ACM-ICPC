l, d = [0,], 1
for i in range(10 ** 6 // 2):
    l.append(l[-1] + d)
    l.append(l[-1] + d)
    d += 1
for i in range(1, len(l)):
    l[i] += l[i - 1]

while True:
    n = int(input())
    if n < 3:
        break
    print(l[n - 3])
