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

int LA, LS;
V<int> arr;
V<int> seg;
int mq;
void build(int sl, int sr, int si) {
	if (sl == sr) {
		seg[si] = arr[sl];
		return;
	}
	int mid = sl + (sr - sl) / 2;
	int nl = si * 2 + 1;
	int nr = si * 2 + 2;
	build(sl, mid, nl);
	build(mid + 1, sr, nr);
	seg[si] = seg[nl] + seg[nr];
}
int query(int al, int ar) {
	int nq = 0;
	F<int(int, int, int)> que = [&] (int sl, int sr, int si) -> int {
		nq ++;
		if (ar < sl || sr < al) {
			return 0;
		}
		if (al <= sl && sr <= ar) {
			return seg[si];
		}
		int mid = sl + (sr - sl) / 2;
		return que(sl, mid, si * 2 + 1) 
			+ que(mid + 1, sr, si * 2 + 2);
	};
	int rr = que(0, LA - 1, 0);
	mq = max(mq, nq);
	return rr;
}
int main() {
	for (int d = 1; d <= 1000; d ++) {
		arr.psb(d);
	}
	LA = arr.size();
	LS = LA * 4;
	seg = V<int>(LS);
	build(0, LA - 1, 0);
	for (int i = 0; i < LA; i ++) {
		for (int j = i + 1; j < LA; j ++) {
			query(i, j);
			/*
			int rr = query(i, j);
			db(i, j, rr);
			*/
		}
	}
	db(mq);
	return 0;
}
