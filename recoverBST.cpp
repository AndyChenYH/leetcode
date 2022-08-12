#include "../utils.cpp"
#include "TreeNode.cpp"
using namespace std;

int main() {
	TreeNode *root =
		new TreeNode(3,
				new TreeNode(1),
				new TreeNode(4,
					new TreeNode(2),
					nullptr));
	vector<int> ar;
	function<void(TreeNode*)> trav = [&] (TreeNode *n) {
		if (n == nullptr) return;
		trav(n->left);
		ar.push_back(n->val);
		trav(n->right);
	};
	trav(root);
	int a = 0, b = 0;
	for (int i = 0; i < ar.size() - 1; i ++) {
		if (ar[i] > ar[i + 1]) {
			a = i;
			break;
		}
	}
	for (int i = ar.size() - 1; 1 <= i; i --) {
		if (ar[i] < ar[i - 1]) {
			b = i;
			break;
		}
	}
	TreeNode *aa = new TreeNode(), *bb = new TreeNode();
	function<void(TreeNode*)> sol = [&] (TreeNode *n) {
		if (n == nullptr) return;
		sol(n->left);
		if (n->val == ar[a]) aa = n;
		else if (n->val == ar[b]) bb = n;
		sol(n->right);
	};
	sol(root);
	aa->val = ar[b], bb->val = ar[a];
	cout << root;
}
