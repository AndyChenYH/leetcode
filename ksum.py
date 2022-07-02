ar = [1,0,-1,0,-2,2]
target = 0
ar.sort()
def twosum(tar):
    l = j + 1; r = len(ar) - 1
    while l < r:
        sm = ar[l] + ar[r]
        if sm == tar:
            return [ar[l], ar[r]]
            break
        elif sm < tar: l += 1
        elif tar < sm: r -= 1
    return []

