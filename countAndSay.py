'''
n = 4

lis = [1]
for cc in range(n - 1):
    num = lis[0]
    ct = 0
    res = []

    for i in range(len(lis)):
        if lis[i] != num:
            res.append(ct)
            res.append(num)
            num = lis[i]
            ct = 1

        else:
            ct += 1
    res.append(ct)
    res.append(num)
    lis = res
    print(lis)
'''
n = 4
lis = [1]
for cc in range(n - 1):
    num = lis[0]
    ct = 0
    res = []

    for i in range(len(lis)):
        if lis[i] != num:
            res.append(ct)
            res.append(num)
            num = lis[i]
            ct = 1

        else:
            ct += 1
    res.append(ct)
    res.append(num)
    lis = res
r = 0
for d in lis:
    r = r * 10 + d
print(lis)
