nums = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
tar = 27

nums.sort()
cur = []
res = set()
def sol(s, sm):
    if sm > tar: return
    if sm == tar:
        res.add(tuple(cur.copy()))
        return
    if s >= len(nums): return
    for i in range(s, len(nums)):
        cur.append(nums[i])
        sol(i + 1, sm + nums[i])
        cur.pop()

sol(0, 0)

res = [list(l) for l in list(res)]
print(res)

