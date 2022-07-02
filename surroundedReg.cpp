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
V<V<char>> mb;
V<V<T<int, int, bool>>> uf;
pii fid(pii u) {
	if (mkp(get<0>(uf[u.fi][u.se]), get<1>(uf[u.fi][u.se])) == u) {
		return u;
	}
	else {
		pii rt = fid({get<0>(uf[u.fi][u.se]), get<1>(uf[u.fi][u.se])});
		get<0>(uf[u.fi][u.se]) = rt.fi;
		get<1>(uf[u.fi][u.se]) = rt.se;
		return rt;
	}
}
void un(pii u, pii v) {
	pii pu = fid(u);
	pii pv = fid(v);
	bool bo = get<2>(uf[pu.fi][pu.se]) || get<2>(uf[pv.fi][pv.se]);
	get<0>(uf[pu.fi][pu.se]) = pv.fi;
	get<1>(uf[pu.fi][pu.se]) = pv.se;
	get<2>(uf[pv.fi][pv.se]) = bo;
}

void pt() {
	V<V<bool>> dd(LR, V<bool>(LC));
	for (int i = 0; i < LR; i ++) {
		for (int j = 0; j < LC; j ++) {
			pii pp = fid({get<0>(uf[i][j]), get<1>(uf[i][j])});
			dd[i][j] = get<2>(uf[pp.fi][pp.se]);
		}
	}
	db(pmG(dd));
}
int main() {
	mb = {
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'},
	};
	LR = mb.size();
	LC = mb[0].size();
	uf = V<V<T<int, int, bool>>>(LR, V<T<int, int, bool>>(LC));
	for (int i = 0; i < LR; i ++) {
		for (int j = 0; j < LC; j ++) {
			if (mb[i][j] == 'O' && (i == 0 || i == LR - 1 || j == 0 || j == LC - 1)) {
				uf[i][j] = {i, j, true};
			}
			else {
				uf[i][j] = {i, j, false};
			}
		}
	}
	auto can = [&] (int i, int j) -> bool {
		return 0 <= i && i < LR && 0 <= j && j < LC;
	};
	for (int i = 0; i < LR; i ++) {
		for (int j = 0; j < LC; j ++) {
			if (mb[i][j] == 'O') {
				for (pii dr : drs) {
					int ni = i + dr.fi;
					int nj = j + dr.se;
					if (can(ni, nj) && mb[ni][nj] == 'O') {
						un({i, j}, {ni, nj});
					}
				}
			}
		}
	}
	for (int i = 0; i < LR; i ++) {
		for (int j = 0; j < LC; j ++) {
			pii f = fid({i, j});
			if (mb[i][j] == 'O' && !get<2>(uf[f.fi][f.se])) {
				mb[i][j] = 'X';
			}
		}
	}
	db(mb);
	return 0;
}
