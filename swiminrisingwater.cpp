#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define psb push_back
#define mkp make_pair
#define mkt make_trip
#define fi first
#define se second
#define th third
#define E exit(0)
#define F function
#define V vector
#define pii pair<int, int>
#define tiii trip<int, int, int>
#define ll long long
#define S string
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define MOD 1000000007
#define INF (2147483647 / 2)
#define printf(args...) fprintf(stderr, ##args)
#define TLE throw logic_error("oops")
using namespace std;

int NS;
V<V<int>> hts;
V<V<char>> vis;
const V<pii> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool bound(int i, int j) {
	return 0 <= i && i < NS && 0 <= j && j < NS;
}
int mht;
bool yes;
void dfs(pii u) {
	if (mht < hts[u.fi][u.se]) { return; }
	if (u.fi == NS - 1 && u.se == NS - 1) {
		yes = true;
		return;
	}
	vis[u.fi][u.se] = 'b';
	for (pii dir : dirs) {
		int ni = u.fi + dir.fi;
		int nj = u.se + dir.se;
		if (bound(ni, nj) && vis[ni][nj] == 'w') {
			dfs({ni, nj});
		}
	}
}
int main() {
	hts = {
		{11,15,3,2},
		{6,4,0,13},
		{5,8,9,10},
		{1,14,12,7},
	};
	NS = hts.size();
	auto sim = [&] (int ht) -> bool {
		mht = ht;
		vis = V<V<char>>(NS, V<char>(NS, 'w'));
		yes = false;
		dfs({0, 0});
		return yes;
	};
	// sol2
	int L = 0, R = 1;
	while (!sim(R)) {
		R *= 2;
	}
	int ans = -1;
	while (L <= R) {
		int mid = L + (R - L) / 2;
		int res = sim(mid);
		if (!res) {
			L = mid + 1;
		}
		else {
			if (ans == -1 || mid < ans) {
				ans = mid;
			}
			R = mid - 1;	
		}
	}
	db(ans);
	return 0;
}
