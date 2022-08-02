#include "../utils.cpp"
#include "TreeNode.cpp"
using namespace std;

TreeNode* sol(vector<int> p, vector<int> i) {
	if (p.empty()) {
		assert(i.empty());
		return nullptr;
	}
	TreeNode *res = new TreeNode(p[0]);
	int ind = find(i.begin(), i.end(), p[0]) - i.begin();
	vector<int> a(p.begin() + 1, p.begin() + ind + 1);
	vector<int> b(i.begin(), i.begin() + ind);
	vector<int> c(p.begin() + ind + 1, p.end());
	vector<int> d(i.begin() + ind + 1, i.end());
	res->left = sol(a, b);
	res->right = sol(c, d);
	return res;
}
int main() {
	cout << sol({1, 2, 4, 5, 3}, {4, 2, 5, 1, 3});
	cout << sol({3,9,20,15,7}, {9,3,15,20,7});
	cout << sol({-1}, {-1});
}
