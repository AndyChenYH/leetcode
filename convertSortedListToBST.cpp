#include "../utils.cpp"
#include "TreeNode.cpp"
#include "LinkedList.cpp"
using namespace std;


ListNode* lis = fromV({1, 2, 3, 4, 5, 6, 7, 8, 9});
// n is number of nodes in tree
TreeNode* sol(int n) {
	if (n == 0) return nullptr;
	if (n == 1) {
		TreeNode* res = new TreeNode(lis->val);
		lis = lis->next;
		return res;
	}
	TreeNode* l;
	if (n % 2 == 0) l = sol(n / 2 - 1);
	else l = sol(n / 2);
	TreeNode* res = new TreeNode(lis->val);
	lis = lis->next;
	TreeNode* r = sol(n / 2);
	res->left = l, res->right = r;
	return res;
}
int main() {
	int s = 0;
	ListNode* cur = lis;
	while (cur != nullptr) {
		s ++;
		cur = cur->next;
	}
	TreeNode* res = sol(s);
	cout << res;
}
