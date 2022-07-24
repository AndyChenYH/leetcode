/*
 * since inorder traversal is not a tail-recursive function,
 * we have to using something more complex than just a simple stack
 * here, when considering recursion, there are really just two states:
 *		1. going foward
 *		2. backup (ie. backtracking)
 *	so we set a state to keep track of whether we are searching deeper into the tree or coming back
 *	hence using a simple DFA
 */
// the recursive function we are modeling after:
void recur(TreeNode* current) {
	if (current == nullptr) return;
	recur(current->left);
	printf("%d\n", current->val); // or add current->val to resulting list
	recur(current->right);
}
class Solution {
	public:
		vector<int> inorderTraversal(TreeNode* root) {
			vector<int> res;
			// using a linkedlist as model for stack
			list<TreeNode*> st;
			// 0 is forward, 1 is back
			int state = 0;
			// equivalent to calling recur(root);
			st.push_back(root);
			// make sure recursive function ends when the stack is empty
			while (!st.empty()) {
				TreeNode* n = st.back();
				if (state == 0) {
					// reaching the bottom of the tree, thus going back up
					if (n == nullptr) {
						state = 1;
					}
					else {
						st.push_back(n->left);
					}
				}
				else if (state == 1) {
					// pop off empty nodes at the bottom
					if (n == nullptr) {
						st.pop_back();
					}
					else {
						res.push_back(n->val);
						st.pop_back();
						st.push_back(n->right);
						state = 0;
					}
				}
			}
			return res;
		}
};
