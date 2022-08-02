#include "../utils.cpp"
#include "unordered_map"
#include "TreeNode.cpp"
using namespace std;

unordered_map<pair<int, int>, int> mem;
int gen(int lo, int hi) {
	if (mem.find({lo, hi}) != mem.end()) return mem[{lo, hi}];
	if (hi - lo == 0) return 1;
	int res = 0;
	for (int i = lo; i < hi; i ++) {
		int l = gen(lo, i);
		int r = gen(i + 1, hi);
		res += l * r;
	}
	mem.insert({{lo, hi}, res});
	return res;
}

int main() {
	int n = 6;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	for (int lo = n; 0 <= lo; lo --) {
		for (int hi = lo; hi <= n; hi ++) {
			if (hi - lo == 0) dp[lo][hi] = 1;
			else {
				int res = 0;
				for (int i = lo; i < hi; i ++) {
					res += dp[lo][i] * dp[i + 1][
				}
			}
		}
	}
}
