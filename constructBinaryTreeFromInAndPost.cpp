#include "../utils.cpp"
#include "TreeNode.cpp"
using namespace std;

TreeNode* sol(vector<int> i, vector<int> p) {
	if (p.empty()) {
		return nullptr;
	}
	TreeNode *res = new TreeNode(p.back());
	auto fid = find(i.begin(), i.end(), p.back());
	int ind = i.end() - 1 - fid;
	vector<int> ir(fid, i.end());
	vector<int> il(i.begin(), fid);
	vector<int> pr(p.end() - 1 - ind, p.end() - 1);
	vector<int> pl(p.begin(), p.end() - 1 - ind);
	res->right = sol(ir, pr);
	res->left = sol(il, pl);
	return res;
}
int main() {
	vector<int> i = {9,3,15,20,7}, p = {9,15,7,20,3};
	cout << sol(i, p);
}
