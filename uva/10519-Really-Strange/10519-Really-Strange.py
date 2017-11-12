n = 0
while True:
    try:
        n = int(input())
        print(str((n - 1) * n + 2) if n > 0 else "1")
    except:
        break
