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
V<pii> qs;
V<V<pii>> uf;
V<V<bool>> mb;
pii fid(pii u) {
	if (uf[u.fi][u.se] == u) {
		return u;
	}
	pii rt = fid(uf[u.fi][u.se]);
	uf[u.fi][u.se] = rt;
	return rt;
}
void un(pii u, pii v) {
	pii pu = fid(u);
	uf[pu.fi][pu.se] = fid(v);
}
int main() {
	LR = 3, LC = 3;
	mb = V<V<bool>>(LR, V<bool>(LC, 0));
	uf = V<V<pii>>(LR, V<pii>(LC));
	for (int i = 0; i < LR; i ++) {
		for (int j = 0; j < LC; j ++) {
			uf[i][j] = {i, j};
		}
	}
	qs = {{0, 0}, {0, 1}, {1, 2}, {2, 1}, {2, 2}, {1, 1}};
	auto can = [&] (int i, int j) -> bool {
		return 0 <= i && i < LR && 0 <= j && j < LC;
	};
	int ct = 0;
	V<int> res = {};
	for (pii q : qs) {
		if (mb[q.fi][q.se] != 1) {
			mb[q.fi][q.se] = 1;
			bool ha = false;
			for (pii dr : drs) {
				int ni = q.fi + dr.fi;
				int nj = q.se + dr.se;
				if (can(ni, nj) && mb[ni][nj] == 1) {
					ha = true;
					if (fid(q) != q && fid(q) != fid({ni, nj})) {
						ct --;
					}
					un(q, {ni, nj});
				}
			}
			if (!ha) {
				ct ++;
			}
		}
		res.psb(ct);
	}
	db(res);
	return 0;
}
