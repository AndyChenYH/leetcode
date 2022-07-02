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

int LN;
V<V<int>> mG;
V<pii> uf;
int fid(int u) {
	if (uf[u].fi == u) {
		return u;
	}
	int rt = fid(uf[u].fi);
	uf[u].fi = rt;
	return rt;
}
void un(int u, int v) {
	pii pu = uf[fid(u)];
	pii pv = uf[fid(v)];
	if (pu == pv) { return; }
	uf[pu.fi].se += uf[pv.fi].se;
	uf[pv.fi].fi = pu.fi;
}
int main() {
	mG = {
		{1, 1, 0},
		{1, 1, 1},
		{0, 1, 1},
	};
	LN = mG.size();
	uf = V<pii>(LN);
	for (int u = 0; u < LN; u ++) {
		uf[u] = {u, 1};
	}
	for (int i = 0; i < LN; i ++) {
		for (int j = 0; j < LN; j ++) {
			if (mG[i][j] != 0) {
				un(i, j);			
			}
		}
	}
	unordered_set<int> pps = {};
	for (pii pu : uf) {
		pps.insert(fid(pu.fi));
	}
	db(pps);
	return 0;
}
