ar = [1,0,-1,0,-2,2]
ar.sort()
target = 0
N = len(ar)
res = []
def twosum(tar, l, r):
    while l < r:
        sm = ar[l] + ar[r]
        if sm == tar:
            return [ar[l], ar[r]]
            break
        elif sm < tar: l += 1
        elif tar < sm: r -= 1
    return []

for i in range(N):
    for j in range(i + 1, N):
        sm = twosum(target - ar[i] - ar[j], j + 1, N - 1)
        if sm != []: res.append([ar[i], ar[j]] + sm)
print(res)
