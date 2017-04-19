tc = int(input())
for i in range(tc):
    try:
        str = input()
        ans = eval(str)
        if '-' in str:
            print("ERROR")
        else:
            print(ans)
    except:
        print("ERROR")
