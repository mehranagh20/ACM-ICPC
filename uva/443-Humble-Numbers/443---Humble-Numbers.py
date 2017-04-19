from math import pow

l = []
mx = 2001000

SUFFIXES = {1: 'st', 2: 'nd', 3: 'rd'}
def ordinal(num):
    if 10 <= num % 100 <= 20:
        suffix = 'th'
    else:
        suffix = SUFFIXES.get(num % 10, 'th')
    return str(num) + suffix

for i in range(32):
    for j in range(22):
        for k in range(15):
            for d in range(13):
                l.append(int(pow(2, i) * pow(3, j) * pow(5, k) * pow(7, d)))

l = sorted(l)

while True:
    n = int(input())
    if n == 0:
        break
    print("The " + str(ordinal(n)) + " humble number is " + str(l[n - 1]) + ".")
