import math
while True:
    try:
        n = int(input())
        print("%d!" % (n))
        print(math.factorial(n))
    except:
        break
