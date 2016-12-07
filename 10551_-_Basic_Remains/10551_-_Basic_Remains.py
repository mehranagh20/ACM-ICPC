def numberToBase(n, b):
    if n == 0:
        return ['0']
    digits = []
    while n >= 1:
        digits.append(str(int(n % b)))
        n /= b
    return digits[::-1]

while True:
    nums = [a for a in input().split()]
    if len(nums) == 1:
        break
    first, second = int(nums[1], int(nums[0])), int(nums[2], int(nums[0]))
    print(''.join(numberToBase(first % second, int(nums[0]))))