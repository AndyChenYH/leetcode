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
void build(int sl, int sr, int si) {
	if (sl == sr) {
		seg[si] = arr[sl];
		return;
	}
	else {
		int mid = sl + (sr - sl) / 2;
		int nl = si * 2 + 1, nr = si * 2 + 2;
		build(sl, mid, nl);
		build(mid + 1, sr, nr);
		seg[si] = seg[nl] + seg[nr];
	}
}
int query(int al, int ar) {
	F<int(int, int, int)> que = [&] (int sl, int sr, int si) -> int {
		if (sr < al || ar < sl) {
			return 0;
		}
		else if (al <= sl && sr <= ar) {
			return seg[si];
		}
		else {
			int mid = sl + (sr - sl) / 2;
			int r1 = que(sl, mid, si * 2 + 1);
			int r2 = que(mid + 1, sr, si * 2 + 2);
			return r1 + r2;
		}
	};
	return que(0, LA - 1, 0);
}
void update(int ai, int val) {
	int diff = val - arr[ai];
	arr[ai] += diff;
	F<void(int, int, int)> up = 
		[&] (int sl, int sr, int si) -> void {
		if (ai < sl || sr < ai) {
			return;
		}
		if (sl <= ai && ai <= sr) {
			seg[si] += diff;
		}
		if (sl == sr) { return; }
		int mid = sl + (sr - sl) / 2;
		up(sl, mid, si * 2 + 1);
		up(mid + 1, sr, si * 2 + 2);
	};
	return up(0, LA - 1, 0);
}
int main() {
	arr = {1, 3, 5};
	LA = arr.size();
	LS = LA * 4;
	seg = V<int>(LS);
	build(0, LA - 1, 0);
	db(query(0, 2));
	update(1, 2);
	db(query(0, 2));
	return 0;
}
