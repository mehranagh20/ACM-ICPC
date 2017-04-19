tc = int(input())
for i in range(tc):
    a, b = input().split()
    print(int(str(int(a[::-1]) + int(b[::-1]))[::-1]))