listofnum = list(map(int, input().split()))
print(listofnum)
while len(listofnum) != 0:
    num = listofnum[0]
    count = 0
    count = listofnum.count(num)
    for i in range(count):
        listofnum.remove(num)
    print(num, count)
