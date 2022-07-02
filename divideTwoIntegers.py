
hi = 7
lo = -3 
sign = 0
if (hi < 0 and lo < 0) or (0 < hi and 0 < lo) : sign = 1
else: sign = -1

hi = abs(hi)
lo = abs(lo)
def even(a):
    half = a >> 1
    return half + half == a
def mul(a, b):
    if a == 0 or b == 0: return 0
    if a == 1: return b
    if b == 1: return a
    m = a >> 1
    res = mul(m, b)
    if even(a):
        return res + res
    else:
        return res + b + res

l = 1
r = hi
ans = -1
while l <= r:
    m = l + ((r - l) >> 1)
    res = mul(lo, m)
    if res <= hi:
        ans = m
        l = m + 1
    else:
        r = m - 1
print(ans * sign)
