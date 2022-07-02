n1 = "123"
n2 = "456"

a = [int(d) for d in n1]
b = [int(d) for d in n2]

b = b[::-1]
res = 0
p = 0
for k in range(len(b)):
    dig = []
    carry = 0
    for i in range(len(a) - 1, -1, -1):
        n = a[i] * b[k] + carry
        dig.append(n % 10);
        carry = n // 10
    if carry > 0: dig.append(carry);
    pp = p
    for d in dig:
        print("d: ", d * 10 ** pp);
        res += d * 10 ** pp
        pp += 1
    p += 1
print(res)
