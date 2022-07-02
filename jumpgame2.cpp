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
V<int> arr;
V<int> seg;
void build() {
	function<void(int, int, int)> bu = [&] (int sl, int sr, int si) -> void {
		if (sl == sr) {
			seg[si] = arr[sl];
			return;
		}
		else {
			int mid = sl + (sr - sl) / 2;
			int nl = si * 2 + 1, nr = si * 2 + 2;
			bu(sl, mid, nl);
			bu(mid + 1, sr, nr);
			seg[si] = min(seg[nl], seg[nr]);
		}
	};
	bu(0, LN - 1, 0);
}
int query(int al, int ar) {
	function<int(int, int, int)> que = [&] (int sl, int sr, int si) -> int {
		if (sr < al || ar < sl) {
			return INF;
		}
		else if (al <= sl && sr <= ar) {
			return seg[si];
		}
		else {
			int mid = sl + (sr - sl) / 2;
			int r1 = que(sl, mid, si * 2 + 1);
			int r2 = que(mid + 1, sr, si * 2 + 2);
			return min(r1, r2);
		}
	};
	return que(0, LN - 1, 0);
}
void update(int ai, int val) {
	function<void(int, int, int)> up = [&] (int sl, int sr, int si) -> void {
		if (ai < sl || sr < ai) {
			return;
		}
		if (sl == sr) { 
			seg[si] = val;
			return; 
		}
		int mid = sl + (sr - sl) / 2;
		int nl = si * 2 + 1, nr = si * 2 + 2;
		up(sl, mid, nl);
		up(mid + 1, sr, nr);
		seg[si] = min(seg[nl], seg[nr]);
	};
	up(0, LN - 1, 0);
}

int main() {
	arr = {2, 3, 1, 1, 4};
	LN = arr.size();
	int LS = 2 * int(pow(2, ceil(log2(LN)))) - 1;
	seg = V<int>(LS, INF);
	update(LN - 1, 0);
	for (int i = LN - 2; 0 <= i; i --) {
		int lb = i, rb = min(i + arr[i], LN - 1);
		int m = query(lb, rb);
		update(i, 1 + m);
	}
	int rr = query(0, 0);
	db(rr);
	return 0;
}
