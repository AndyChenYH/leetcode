#include "../utils.cpp"
#include "TreeNode.cpp"
using namespace std;

bool sol(TreeNode* l, TreeNode* r) {
	if (l == nullptr || r == nullptr) {
		if (l != nullptr || r != nullptr) return false;
		return true;
	}
	if (l->val != r->val) return false;
	return sol(l->left, r->right) && sol(l->right, r->left);

}

int main() {
	TreeNode* root = 
		new TreeNode(1,
				new TreeNode(2, 
					new TreeNode(3),
					new TreeNode(4)),
				new TreeNode(2,
					new TreeNode(4),
					new TreeNode(3)));
	printf("%d\n", sol(root->left, root->right));
}

