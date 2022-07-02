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
V<V<int>> mb, tmb;
V<V<pii>> uf;
V<V<T<bool, int>>> att;
pii fid(pii u) {
	if (uf[u.fi][u.se] == u) {
		return u;
	}
	pii rt = fid(uf[u.fi][u.se]);
	uf[u.fi][u.se] = rt;
	return rt;
}
void un(pii u, pii v) {
	pii pu = fid(u), pv = fid(v);
	if (pu == pv) { return; }
	T<bool, int> &au = att[pu.fi][pu.se], &av = att[pv.fi][pv.se];
	get<0>(av) = get<0>(au) || get<0>(av);
	get<1>(av) += get<1>(au);
	uf[pu.fi][pu.se] = pv;
}
bool can(int i, int j) {
	return 0 <= i && i < LR && 0 <= j && j < LC;
}
int main() {
	mb = {
		{1, 0, 1, 0},
		{1, 1, 1, 0},
		{0, 0, 0, 0},
	};
	tmb = mb;
	qs = {{1, 0}, {1, 2}};
	LR = mb.size();
	LC = mb[0].size();
	uf = V<V<pii>>(LR, V<pii>(LC));
	att = V<V<T<bool, int>>>(LR, V<T<bool, int>>(LC));
	for (pii q : qs) {
		mb[q.fi][q.se] = 0;
	}

	for (int i = 0; i < LR; i ++) {
		for (int j = 0; j < LC; j ++) {
			if (mb[i][j] == 1) {
				uf[i][j] = {i, j};
				bool si = i == 0;
				att[i][j] = {si, 1};
			}
		}
	}
	for (int i = 0; i < LR; i ++) {
		for (int j = 0; j < LC; j ++) {
			if (mb[i][j] == 1) {
				for (pii dr : drs) {
					int ni = i + dr.fi, nj = j + dr.se;
					if (can(ni, nj) && mb[ni][nj] == 1) {
						un({i, j}, {ni, nj});
					}
				}
			}
		}
	}
	db(mb, uf, att);
	reverse(qs.begin(), qs.end());
	V<int> res = {};
	int ct = 0;
	for (pii q : qs) {
		if (tmb[q.fi][q.se] == 1) {
			mb[q.fi][q.se] = 1;
			uf[q.fi][q.se] = q;
			att[q.fi][q.se] = {q.fi == 0, 1};
			for (pii dr : drs) {
				int ni = q.fi + dr.fi, nj = q.se + dr.se;
				if (can(ni, nj) && mb[ni][nj] == 1) {
					if (fid(q) == fid({ni, nj})) {
						continue;
					}
					if (get<0>(att[fid({ni, nj}).fi][fid({ni, nj}).se])) {
						if (!get<0>(att[fid(q).fi][fid(q).se]) && 1 < get<1>(att[fid(q).fi][fid(q).se])) {
							ct += get<1>(att[fid(q).fi][fid(q).se]) - 1;
						}
					}
					else {
						if (get<0>(att[fid(q).fi][fid(q).se])) {
							ct += get<1>(att[fid({ni, nj}).fi][fid({ni, nj}).se]);
						}
					}
					un(q, {ni, nj});
				}
			}
		}
		res.psb(ct);
	}
	reverse(res.begin(), res.end());
	db(mb, uf, att);
	db(res);
	return 0;
}
