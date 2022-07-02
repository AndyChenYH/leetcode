#include <vector>
#include "../utils.cpp"
#include <iostream>
using namespace std;

// solution 1:
/*
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

int main() {
	vector<int> ar = {0, 1};
	auto p = permute(ar);
	db(p);
}
*/

vector<vector<int>> permute(vector<int>& ar) {
	vector<vector<int>> res;
	function<void(int)> sol = [&] (int i) {
		if (i == ar.size() - 1) {
			res.push_back({ar});
			return;
		}
		for (int ii = i; ii < ar.size(); ii ++) {
			swap(ar[ii], ar[i]);
			sol(i + 1);
			swap(ar[ii], ar[i]);
		}
	};
	sol(0);
	return res;

}
int main() {
	vector<int> ar = {1, 2, 3, 4, 5, 6};
	auto p = permute(ar);
	db(p);
}
