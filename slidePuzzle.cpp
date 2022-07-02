#include <bits/stdc++.h>
//#include "utils.cpp"
#define itr iterator
#define psb push_back
#define mkp make_pair
#define fi first
#define se second
#define E exit(0)
#define F function
#define V vector
#define pii pair<int, int>
#define ll long long
#define S string
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define MOD int(1e9 + 7)
#define INF (INT_MAX / 2)
using namespace std;

namespace std {
	template <typename T>
	struct hash<V<T>> {
		int operator () (V<T> v) const {
			ll res = 17;
			for (T t : v) {
				res = ((res * 31) % MOD + hash<T>()(t)) % MOD;
			}
			return int(res % MOD);
		}
	};
}

const int LR = 2, LC = 3;
const V<V<int>> tar = {
	{1, 2, 3},
	{4, 5, 0},
};
const vector<pair<int, int>> drs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
unordered_set<V<V<int>>> vis;
V<V<int>> mb;
bool can(int i, int j) {
	return 0 <= i && i < LR && 0 <= j && j < LC;
}
int main() {
	mb = {
		{4, 1, 2},
		{5, 0, 3},
	};
	vis = {};
	auto sol = [&] () -> int {
		queue<pair<V<V<int>>, int>> que;
		que.push({mb, 0});
		while (!que.empty()) {
			pair<V<V<int>>, int> fr = que.front();
			que.pop();
			for (int i = 0; i < LR; i ++) {  // L1
				for (int j = 0; j < LC; j ++) {
					if (fr.fi[i][j] == 0) {
						for (pii dr : drs) {
							int ni = i + dr.fi;
							int nj = j + dr.se;
							if (can(ni, nj)) {
								V<V<int>> tmp = fr.fi;
								swap(tmp[i][j], tmp[ni][nj]);
								if (vis.find(tmp) == vis.end()) {
									vis.insert(tmp);
									que.push({tmp, fr.se + 1});
									if (tmp == tar) {
										return fr.se + 1;
									}
								}
							}
						}
						goto L1;
					}
				}
			}
L1:;
		}
		return -1;
	};
	int rr = sol();
	cerr << rr << endl;
			
	return 0;
}
