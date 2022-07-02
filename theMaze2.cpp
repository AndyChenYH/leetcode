#include <bits/stdc++.h>
#include "utils.cpp"
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

const vector<pair<int, int>> drs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int LR, LC;
pii ss, dd;
V<V<int>> mb;
V<V<int>> mnd;
bool can(int i, int j) {
	return 0 <= i && i < LR && 0 <= j && j < LC && mb[i][j] == 0;
}
int dist(pii a, pii b) {
	int dx = abs(a.fi - b.fi);
	int dy = abs(a.se - b.se);
	return dx + dy;
}
int main() {
	ss = {0, 4}, dd = {4, 4};
	mb = {
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0},
		{1, 1, 0, 1, 1},
		{0, 0, 0, 0, 0},
	};
	LR = mb.size();
	LC = mb[0].size();
	mnd = V<V<int>>(LR, V<int>(LC, INF));
	queue<pii> que;
	que.push(ss);
	mnd[ss.fi][ss.se] = 0;
	while (!que.empty()) {
		pii fr = que.front();
		que.pop();
		for (pii dr : drs) {
			pii nf = fr;
			while (can(nf.fi, nf.se)) {
				nf.fi += dr.fi;
				nf.se += dr.se;
			}
			nf.fi -= dr.fi;
			nf.se -= dr.se;
			if (nf == fr) { continue; }

			int nd = mnd[fr.fi][fr.se] + dist(fr, nf);
			if (nd < mnd[nf.fi][nf.se]) {
				mnd[nf.fi][nf.se] = nd;
				que.push(nf);
			}
		}
	}
	for (V<int>& v : mnd) {
		for (int& d : v) {
			if (d == INF) {
				d = -1;
			}
		}
	}
	db(mnd);
	db(mnd[dd.fi][dd.se]);
	return 0;
}
