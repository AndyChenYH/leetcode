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
V<V<bool>> vis;
V<V<bool>> mb;
bool can(int i, int j) {
	return 0 <= i && i < LR && 0 <= j && j < LC && mb[i][j] == 0;
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
	bool yes = false;
	vis = V<V<bool>>(LR, V<bool>(LC, false));
	queue<pii> que;
	que.push(ss);
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
			if (!vis[nf.fi][nf.se]) {
				if (nf == dd) {
					yes = true;
					goto L1;
				}
				vis[nf.fi][nf.se] = true;
				que.push(nf);
			}
		}	
	}
L1:;
	db(vis);
	db(yes);
	return 0;
}
