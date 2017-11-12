tc = int(input())
for i in range(0, tc):
    n, k = [int(x) for x in input().split()]
    for d in range(0, 300):
        # print(int((k * (pow(10, d) - n)) / (10 * n - 1)))
        tmp = str(int((k * (pow(10, d) - n)) / (10 * n - 1)))
        if (k * (int(pow(10, d)) - n)) % (10 * n - 1) == 0 and ((len(tmp) == d and d) or (len(tmp) == 1 and d == 0)):
            print(int((k * (pow(10, d) - n)) / (10 * n - 1)) * 10 + k)
            break
        if d == 299:
            print(0)
            break
