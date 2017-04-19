fib = [1, 2]
for i in range(1010):
    fib.append(fib[i] + fib[i + 1])

while True:
    try:
        n = int(input())
        print(fib[n])
    except:
        break
