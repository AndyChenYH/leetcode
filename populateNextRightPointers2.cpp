#include "../utils.cpp"
#include "TreeNode.cpp"
using namespace std;

void pn(TreeNode* n) {
	while (n != nullptr) {
		printf("%d ", n->val);
		n = n->next;
	}
	puts("");
}
int main() {
	TreeNode* root =
		new TreeNode(1,
				new TreeNode(2),
				new TreeNode(3));
	TreeNode* far = nullptr;
	// sentiniel node
	TreeNode* last = new TreeNode();
	TreeNode* cur = root;
	while (true) {
		// set leftmost if it hasn't been set yet
		if (cur->left != nullptr) {
			if (far == nullptr) far = cur->left;
			last = last->next = cur->left;
		}
		// set leftmost if it hasn't been set yet
		if (cur->right != nullptr) {
			if (far == nullptr) far = cur->right;
			last = last->next = cur->right;
		}
		if (cur->next == nullptr) {
			if (far == nullptr) break;
			cur = far;
			far = nullptr;
			last = new TreeNode();
		}
		else cur = cur->next;
	}
}
