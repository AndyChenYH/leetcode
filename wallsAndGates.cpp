#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define psb push_back
#define mkp make_pair
#define mkt make_tuple
#define fi first
#define se second
#define T tuple
#define E exit(0)
#define F function
#define V vector
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ll long long
#define S string
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define MOD int(1e9 + 7)
#define INF (INT_MAX / 2)
using namespace std;

const vector<pair<int, int>> drs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int LR, LC;
V<V<int>> mb;
int main() {
	mb = {
		{INF, -1, 0, INF},
		{INF, INF, INF, -1},
		{INF, -1, INF, -1},
		{0, -1, INF, INF},
	};
	LR = mb.size();
	LC = mb[0].size();
	queue<tiii> que;
	for (int i = 0; i < LR; i ++) {
		for (int j = 0; j < LC; j ++) {
			if (mb[i][j] == 0) {
				que.push({i, j, 0});
			}
		}
	}
	auto can = [&] (int i, int j) -> bool {
		return 0 <= i && i < LR && 0 <= j && j < LC;
	};
	while (!que.empty()) {
		tiii fr = que.front();
		que.pop();
		for (pii dr : drs) {
			int ni = get<0>(fr) + dr.fi;
			int nj = get<1>(fr) + dr.se;
			if (can(ni, nj) && mb[ni][nj] != -1 && mb[ni][nj] == INF) {
				int nd = get<2>(fr) + 1;
				mb[ni][nj] = nd;
				que.push({ni, nj, nd});
			}
		}
	}
	db(mb);
	return 0;
}
