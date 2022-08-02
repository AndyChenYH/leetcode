#include "../utils.cpp"
#include "unordered_set"
#include "TreeNode.cpp"
using namespace std;

/*
// long and convoluted solution
vector<vector<int>> permute(vector<int> ar) {
	if (ar.size() == 1) return {ar};
	vector<vector<int>> res;
	for (int i = 0; i < ar.size(); i ++) {
		vector<int> nar = ar;
		nar.erase(nar.begin() + i);
		for (vector<int> v : permute(nar)) {
			v.insert(v.begin(), ar[i]);
			res.push_back(v);
		}

	}
	return res;

}

void insert(TreeNode* root, TreeNode* n) {
	assert(root != nullptr);
	if (root->val < n->val) {
		if (root->right == nullptr) {
			root->right = n;
		}
		else insert(root->right, n);
	}
	else {
		if (root->left == nullptr) {
			root->left = n;
		}
		else insert(root->left, n);
	}
}

int hashTree(TreeNode* root) {
	vector<int> res;
	function<void(TreeNode*, int, int)> recur = [&] (TreeNode* n, int d, int l) {
		if (n == nullptr) return;
		res.push_back(d); res.push_back(l);
		recur(n->left, d + 1, l * 2 - 1);
		recur(n->right, d + 1, l * 2);
	};
	recur(root, 1, 1);
	return hash<vector<int>>()(res);
}
int main() {
	int n = 2;
	vector<int> ar;
	unordered_set<int> seen;
	for (int i = 1; i <= n; i ++) ar.push_back(i);
	for (vector<int> p : permute(ar)) {
		TreeNode* bst = new TreeNode(p[0]);
		for (int i = 1; i < p.size(); i ++) insert(bst, new TreeNode(p[i]));
		int hs = hashTree(bst);
		if (seen.find(hs) == seen.end()) {
			seen.insert(hs);
			cout << bst << endl << endl;
		}
	}
}
*/

vector<TreeNode*> gen(vector<int> ar) {
	if (ar.empty()) return {nullptr};
	vector<TreeNode*> res;
	for (int i = 0; i < ar.size(); i ++) {
		vector<TreeNode*> l = gen(vector<int>(ar.begin(), ar.begin() + i));
		vector<TreeNode*> r = gen(vector<int>(ar.begin() + i + 1, ar.end()));
		for (TreeNode* ll : l) {
			for (TreeNode* rr : r) {
				res.push_back(new TreeNode(ar[i], ll, rr));
			}
		}
	}
	return res;
}
int main() {
	int n = 6;
	vector<int> ar;
	for (int i = 1; i <= n; i ++) ar.push_back(i);
	db(gen(ar).size());
	exit(0);
	for (TreeNode* t : gen(ar)) {
		cout << t << endl;
	}

}
