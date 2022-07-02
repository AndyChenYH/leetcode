#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> ar = {1, 2, 3, 4, 5};
	int t = 14;
	int N = ar.size();
	int k = 4;
	vector<int> ind;
	for (int c = 0; c < k - 2; c ++) {
		ind.push_back(c);
	}
	vector<int> upp;
	for (int c = 0; c < k - 2; c ++) {
		upp.push_back(N - c);
	}
	int lop = 0;
	while (ind < upp) {


		ind[lop] ++;
		// if current iter index has reached upper bound
		if (ind[lop] >= upp[lop]) {
			if (lop == k - 2 - 1) {

			}
		}
	}
}

/*
// two pointer same old same old
int main() {
	vector<int> ar = {1, 2, 3, 4, 5};
	int t = 13;
	function<vector<vector<int>>()> sol = [&] () -> vector<vector<int>> {
		int N = ar.size();
		if (N < 4) return {};
		sort(ar.begin(), ar.end());
		set<vector<int>> res;
		for (int i = 0; i < N - 3; i ++) {
			for (int j = i + 1; j < N - 2; j ++) {
				int l = j + 1, r = N - 1;
				int tar = t - ar[i] - ar[j];
				while (l < r) {
					if (ar[l] + ar[r] == tar) {
						res.insert({ar[i], ar[j], ar[l], ar[r]});
					}
					else if (ar[l] + ar[r] < tar) {
						l ++;
					}
					else r --;
				}
			}
		}
		return vector<vector<int>>(res.begin(), res.end());
	};
	auto res = sol();
	for (vector<int> v : res) {
		for (int d : v) {
			cout << d << " ";
		}
		puts("");
	}

}
*/
