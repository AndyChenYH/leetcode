/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
const long long MN = 1000, INF = INT_MAX;
long long mnl[MN], mxr[MN];
class Solution {
public:
    void ser(TreeNode* n, long long d, long long x) {
        mnl[d] = min(mnl[d], x), mxr[d] = max(mxr[d], x);
        if (n->left != nullptr) {
            ser(n->left, d + 1, x * 2 - 1);
        }
        if (n->right != nullptr) {
            ser(n->right, d + 1, x * 2);
        }
    }
    long long widthOfBinaryTree(TreeNode* root) {
        fill(mnl, mnl + MN, INF); fill(mxr, mxr + MN, -INF);
        ser(root, 0, 1);
        long long mx = -INF;
        for (long long i = 0; i < MN; i ++) {
            // prlong longf("%d: %d %d\n", i, mnl[i], mxr[i]);
            mx = max(mx, mxr[i] - mnl[i] + 1);
        }
        return mx;
    }
};
