'''
# rotate layer by layer method

from math import *
mat = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
N = len(mat)
for layer in range(ceil(N / 2)):
    ln = N - layer * 2
    # swap top and right sides
    for k in range(ln - 1):
        a = mat[layer][layer + k]
        b = mat[layer + k][layer + ln - 1]
        c = mat[layer + ln - 1][layer + ln - 1 - k]
        d = mat[layer + ln - 1 - k][layer]
        a, b, c, d = d, a, b, c
        mat[layer][layer + k] = a
        mat[layer + k][layer + ln - 1] = b
        mat[layer + ln - 1][layer + ln - 1 - k] = c
        mat[layer + ln - 1 - k][layer] = d
print(mat)
'''

# transpose + mirror method
from math import *
mat = [
        [5,1,9,11],
        [2,4,8,10],
        [13,3,6,7],
        [15,14,12,16]
        ]
N = len(mat)
for i in range(1, N):
    for j in range(i):
        mat[i][j], mat[j][i] = mat[j][i], mat[i][j]
for i in range(N):
    for j in range(N // 2):
        mat[i][j], mat[i][N - 1- j] = mat[i][N - 1 - j], mat[i][j]
for row in mat:
    print(row)
