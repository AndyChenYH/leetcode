#include "../utils.cpp"
#include "TreeNode.cpp"
using namespace std;
/*
// simple recursive solution
void recur(TreeNode* cur) {
	if (cur == nullptr) return;
	recur(cur->left);
	printf("%d\n", cur->val);
	recur(cur->right);
}
int main() {
	TreeNode* root = 
		new TreeNode(1,
				new TreeNode(2, 
					new TreeNode(4),
					new TreeNode(5)),
				new TreeNode(3)
				);
	recur(root);
}
*/

/*
// iterative solution based on recursive concept
int main() {
//	TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
	TreeNode* root = 
		new TreeNode(1,
				new TreeNode(2, 
					new TreeNode(4),
					new TreeNode(5)),
				new TreeNode(3)
				);
	list<TreeNode*> st;
	// 0 is forward, 1 is back
	int state = 0;
	st.push_back(root);
	while (!st.empty()) {
		TreeNode* n = st.back();
//		if (n != nullptr && n->val == 2) db(state);
		if (state == 0) {
			if (n == nullptr) {
				state = 1;
			}
			else {
				st.push_back(n->left);
			}
		}
		else if (state == 1) {
			if (n == nullptr) {
				st.pop_back();
			}
			else {
				cout << ">>" << n->val << endl;
				st.pop_back();
				st.push_back(n->right);
				state = 0;
			}
		}
	}
}
*/

/*
// morris traversal O(1) space
int main() {
	TreeNode* root = 
		new TreeNode(1,
				new TreeNode(2, 
					new TreeNode(4),
					new TreeNode(5)),
				new TreeNode(3)
				);
//	TreeNode* root = new TreeNode(1, new TreeNode(2), nullptr);
	TreeNode* cur = root;
	while (true) {
		if (cur->left != nullptr) {
			// reassign rightmost node of left subtree's right to current
			TreeNode* cc = cur->left;
			while (cc->right != nullptr) {
				cc = cc->right;
			}
			cc->right = cur;
			TreeNode* tmp = cur;
			cur = cur->left;
			tmp->left = nullptr;
		}
		else {
			printf("%d\n", cur->val);
			if (cur->right != nullptr) cur = cur->right;
		}
		if (cur->left == nullptr && cur->right == nullptr) {
			printf("%d\n", cur->val);
			break;
		}
	}
}
*/
