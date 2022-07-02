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
#define TLE throw logic_error("oops")
using namespace std;

struct Rt {
	int x1, y1, x2, y2;
};

int LR;
V<Rt> rts;
V<V<int>> r_rts;
V<pii> ptx, pty;
int main() {
	r_rts = {
		{1, 2, 3, 3},
		{3, 1, 4, 2},
		{3, 2, 4, 4},
		{1, 3, 2, 4},
		{2, 3, 3, 4},
	};
	LR = r_rts.size();
	rts = V<int>(LR);
	for (int i = 0; i < LR; i ++) {
		rts[i] = {r_rts[0], r_rts[1], r_rts[2], r_rts[3]};
	}
	ptx = {};
	for (Rt r : rts) {
		ptx.psb({r.x1, r.y1});
		ptx.psb({r.x1, r.y2});
		ptx.psb({r.x2, r.y1});
		ptx.psb({r.x2. r.y2});
	}
	pty = ptx;
	sort(ptx.begin(), ptx.end());

	sort(pty.begin(), pty.end(), [&] (pii a, pii b) -> bool { return a.se < b.se; });
			
	return 0;
}
