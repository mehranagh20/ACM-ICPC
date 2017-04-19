def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

n = int(input())
for i in range(n):
    nums = [int(a) for a in input().split('/')]
    c = gcd(nums[0], nums[1])
    print(nums[0] // c, '/', nums[1] // c)