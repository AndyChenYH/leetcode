
ct = 0
for i in range(5):
    for j in range(i, 5):
        for k in range(j, 5):
            ct += 1
print("first: ", ct)
ct = 0

lVar = [0, 0, 0, 0]
end = [0, 0, 0, 0]
lNum = len(lVar) - 1
while True:
    print(lVar)
    ct += 1
    G1 = False
    for i in range(lNum, -1, -1):
        lVar[i] += 1
        if lVar[i] == end[i] + 1:
            if i == 0:
                G1 = True
                break
            else: 
                lVar[i] = 0
        else: break
    if G1: break
print(ct)

