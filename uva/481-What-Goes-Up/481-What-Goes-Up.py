import sys, re

def fLis(nums):
    b, ans = [None] * len(nums), []
    ans.append(0)
    for i in range(1, len(nums)):
        if(nums[ans[-1]] < nums[i]):
            b[i] = ans[-1]
            ans.append(i)
            continue
        l , r = 0, len(ans) - 1
        while r > l:
            c = (l + r) // 2
            if nums[ans[c]] < nums[i]: l = c + 1
            else: r = c
        if nums[ans[l]] > nums[i]:
            if l > 0: b[i] = ans[l - 1]
            ans[l] = i
    l, r = len(ans) - 1, ans[-1]
    while l >= 0:
        ans[l] = r
        r = b[r]
        l -= 1
    return ans
nums = []
while True:
    try:
        a = int(input())
        nums.append(a)
    except: break
ans = fLis(nums)
print(len(ans))
print("-")
for n in ans: print(nums[n])


