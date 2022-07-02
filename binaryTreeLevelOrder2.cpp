/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 #include <stdio.h>
 #include <vector>
 using namespace std;
 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		vector<TreeNode*> lv;
		res.push_back(root->val);
		lv.push_back(root);
		while (!lv.empty()) {
			vector<TreeNode*> nv;
			vector<int> r;
			for (TreeNode* tn : lv) {
				r.push_back(tn->val);
				if (tn->left != nullptr) {
					nv.push_back(tn->left);
				}
				if (tn->right != nullptr) {
					nv.push_back(tn->right);
				}
			}
			lv = nv;
		}
    }
};

