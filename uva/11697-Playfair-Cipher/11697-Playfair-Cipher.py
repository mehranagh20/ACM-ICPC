tc = int(input())
for t in range(tc):
    key = input().replace(' ', '').upper()
    str = input().replace(' ', '').upper()

    used = [0 for i in range(26)]
    col = [0 for i in range(26)]
    row = [0 for i in range(26)]

    i, j = [0, 0]
    for c in key:
        ind = ord(c) - 65
        if c == 'Q' or used[ind]:
            continue

        used[ind] = 1
        row[ind], col[ind] = [i, j]

        j += 1
        if j == 5:
            i, j = i + 1, 0

    for ind in range(0, 26):
        if used[ind] or ord('Q') - 65 == ind:
            continue

        row[ind], col[ind] = [i, j]
        j += 1
        if j == 5:
            i, j = [i + 1, 0]

    table = [[' ' for i in range(5)] for i in range(5)]
    for i in range(0, 26):
        c = chr(i + 65)
        if c == 'Q':
            continue
        table[row[i]][col[i]] = c


    i = 0
    while i < len(str) - 1:
        if str[i] == str[i + 1]:
            str = str[:i + 1] + 'X' + str[i + 1:]
        i += 2

    if len(str) & 1:
        str += 'X'

    i = 0
    ans = ''
    while i < len(str):
        c1, c2 = [ord(str[i]) - 65, ord(str[i+1]) - 65]
        if row[c1] == row[c2]:
            ans += table[row[c1]][(col[c1] + 1) % 5]
            ans += table[row[c2]][(col[c2] + 1) % 5]

        elif col[c1] == col[c2]:
            ans += table[(row[c1] + 1) % 5][col[c1]]
            ans += table[(row[c2] + 1) % 5][col[c2]]

        else:
            ans += table[row[c1]][col[c2]]
            ans += table[row[c2]][col[c1]]

        i += 2

    print(ans)
