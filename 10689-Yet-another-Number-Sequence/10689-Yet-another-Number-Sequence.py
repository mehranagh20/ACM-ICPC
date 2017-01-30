ra = [60, 300, 1500, 15000]
fib = [0, 1]
for i in range(16000):
    fib.append(fib[i] + fib[i + 1])
tc = int(input())
for i in range(tc):
    a, b, n, m = [int(x) for x in input().split()]
    ind = n % (ra[m - 1])
    print(a % (10 ** m)) if ind == 0 else print(((a * fib[ind - 1] + b * fib[ind])) % (10 ** m))
