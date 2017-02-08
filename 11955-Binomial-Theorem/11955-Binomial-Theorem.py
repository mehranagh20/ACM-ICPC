coefs = [[1]]
for i in range(1, 51):
    coefs.append([1])
    for j in range(1, len(coefs[i-1])):
        coefs[i].append(coefs[i-1][j] + coefs[i-1][j-1])
    coefs[i].append(1)

tc = int(input())
for t in range(1, tc+1):
    tmp, k = input().split('^')
    k = int(k)
    a, b = tmp[1:-1].split('+')

    ans = ""
    for i in range(k+1):
        if i > 0:
            ans += '+'
        if coefs[k][i] > 1:
            ans += (str(coefs[k][i]) + '*')

        if (k-i) > 0:
            ans += a
        if (k-i) > 1:
            ans += '^' + str(k - i)

        if 0 < i < k:
            ans += '*'

        if i > 0:
            ans += b
        if i > 1:
            ans += '^' + str(i)
    print("Case " + str(t) + ": " + ans)
