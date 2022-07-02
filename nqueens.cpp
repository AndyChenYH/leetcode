#include <bits/stdc++.h>
using namespace std;

int main() {
	int N = 6;
	vector<vector<bool>> grid(N, vector<bool>(N, false));
	function<bool(int, int)> bd = [&] (int i, int j) {
		return 0 <= i && i < N && 0 <= j && j < N;
	};
	function<bool(int, int)> att = [&] (int i, int j) {
		vector<pair<int, int>> drs = {
			{-1, -1}, {-1, 0}, {-1, 1},
			{0, -1},         {0, 1},
			{1, -1}, {1, 0}, {1, 1}
		};
		for (pair<int, int> dr : drs) {
			for (int ci = i, cj = j; bd(ci, cj); ci += dr.first, cj += dr.second) {
				if (grid[ci][cj]) return true;
			}
		}
		return false;
	};
	set<vector<vector<bool>>> res;
	function<void(int)> sol = [&] (int ct) {
		if (ct == N + 1) {
			res.insert(grid);
			return;
		}
		for (int i = 0; i < N; i ++) {
			for (int j = 0; j < N; j ++) {
				if (!att(i, j)) {
					grid[i][j] = true;
					sol(ct + 1);
					grid[i][j] = false;
				}
			}
		}
	};
	sol(0);
	vector<vector<string>> ret;
	for (vector<vector<bool>> g : res) {
		vector<string> b(N);
		for (int i = 0; i < N; i ++) {
			for (int j = 0; j < N; j ++) {
				b[i] += g[i][j] ? "Q" : ".";
			}
		}
		ret.push_back(b);
	}
	for (vector<string> g : ret) {
		for (string s : g) {
			cout << s << endl;
		}
		puts("");
	}
}
