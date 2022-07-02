#include <vector>
#include "../utils.cpp"
#include <unordered_set>
#include <iostream>
using namespace std;

int main() {
	vector<int> ar {1, 1, 2};
	unordered_set<vector<int>> st;
	vector<vector<int>> res;
	function<void(int)> sol = [&] (int i) {
		if (i == ar.size() - 1) {
			if (st.find(ar) == st.end()) {
				res.push_back({ar});
				st.insert(ar);
			}
			return;
		}
		for (int ii = i; ii < ar.size(); ii ++) {
			swap(ar[ii], ar[i]);
			sol(i + 1);
			swap(ar[ii], ar[i]);
		}
	};
	sol(0);
	db(res);
}
