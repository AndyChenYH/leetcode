
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from math import *
MN = 1000;
mnl = mxr = [];
def ser(n, d, x):
    mnl[d] = min(mnl[d], x);
    mxr[d] = max(mxr[d], x);
    if (n.left != None):
        ser(n.left, d + 1, x * 2 - 1);
    if (n.right != None):
        ser(n.right, d + 1, x * 2);
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        mnl = [inf for i in range(MN)];
        mxr = [-inf for i in range(MN)];
        ser(root, 0, 1);
        mx = -inf;
        for i in range(MN):
            mx = max(mx, mxr[i] - mnl[i] + 1);
        return mx;
