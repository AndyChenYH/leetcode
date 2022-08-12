#include "../utils.cpp"
#include "TreeNode.cpp"
using namespace std;


vector<vector<int>> res;
vector<int> cur;
void sol(TreeNode *root, int tar) {
	assert(root != nullptr);
	tar -= root->val;
	cur.push_back(root->val);
	if (root->left == nullptr && root->right == nullptr) {
		if (tar == 0) res.push_back(cur);
		cur.pop_back();
		return;
	}
	if (root->left != nullptr) sol(root->left, tar);
	if (root->right != nullptr) sol(root->right, tar);
	cur.pop_back();

}
int main() {
	TreeNode *root = 
		new TreeNode(5,
				new TreeNode(4,
					new TreeNode(11,
						new TreeNode(7),
						new TreeNode(2)),
					nullptr),
				new TreeNode(8,
					new TreeNode(13),
					new TreeNode(4,
						new TreeNode(5),
						new TreeNode(1))));
	int sm = 22;
	sol(root, sm);
	db(res);
}
