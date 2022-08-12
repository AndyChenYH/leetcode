#include "../utils.cpp"
#include "TreeNode.cpp"
using namespace std;

int main() {
	vector<int> ar = {10,3,0,5,9};
	function<TreeNode*(int, int)> sol = [&] (int l, int r) -> TreeNode* {
		db(l, r);
		if (l == r) return nullptr;
		int m = (l + r) / 2;
		return new TreeNode(ar[m], sol(l, m), sol(m + 1, r));
	};
	cout << sol(0, ar.size());
}
