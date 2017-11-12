import math
tc = int(input())
for t in range(tc):
    n, k = [int(x) for x in input().split()]

    last = pow(10, (k * math.log(n, 10)) - math.ceil((k * math.log(n, 10))) + 3)
    first = pow(n, k, 1000)
    print(str(int(last))[:3] + '...' + ((3 - len(str(first))) * '0') + str(first))
