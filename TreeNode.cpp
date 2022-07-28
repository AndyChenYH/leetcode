 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
ostream& operator << ( ostream& out, TreeNode* t) {
	function<void(TreeNode*, int)> p = [&] (TreeNode* t, int dep) {
		if (t == nullptr) return;
		p(t->right, dep + 1);
		for (int i = 0; i < dep; i ++) out << "  ";
		out << t->val << endl;
		p(t->left, dep + 1);
	};
	p(t, 0);
	return out;
}

/*
namespace std 
	template <>
	struct hash<TreeNode*> {
		int operator()( const TreeNode* root ) const {
			vector<int> res;
			function<void(TreeNode*, int, int)> recur = [&] (const TreeNode* n, int d, int l) {
				if (n == nullptr) return;
				res.push_back(d); res.push_back(l);
				recur(n->left, d + 1, l * 2 - 1);
				recur(n->right, d + 1, l * 2);
			};
			recur(root, 1, 1);
			return hash<vector<int>>()(res);
		}
	};
}

*/
