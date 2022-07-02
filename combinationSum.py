nums = [2,3,6,7]
tar = 7
cur = []
res = []
def sol(s, sm):
    if sm > tar: return
    if sm == tar:
        res.append(cur.copy())
        return
    for i in range(s, len(nums)):
        cur.append(nums[i])
        sol(i, sm + nums[i])
        cur.pop()

sol(0, 0)
print(res)

