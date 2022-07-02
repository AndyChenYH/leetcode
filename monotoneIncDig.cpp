#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define psb push_back
#define mkp make_pair
#define mkt make_tuple
#define fi first
#define se second
#define T tuple
#define F function
#define S string
#define V vector
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ll long long
#define E exit(0)
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define MOD int(1e9 + 7)
#define INF (INT_MAX / 2)
using namespace std;

int LN;
int r_num;
V<int> num;
V<int> seg;
void build() {
	function<void(int, int, int)> bu = [&] (int sl, int sr, int si) -> void {
		if (sl == sr) {
			seg[si] = num[sl];
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
int main() {
	r_num = 332;
	num = {};
	for (char c : to_string(r_num)) {
		num.psb(c - '0');
	}
	LN = num.size();
	
	int LS = 2 * int(pow(2, ceil(log2(LN)))) - 1;
	seg = V<int>(LS);
	build();

	V<int> res(LN);
	for (int i = 0; i < LN; i ++) {
		int mn = query(i, LN - 1);
		if (mn < num[i]) {
			res[i] = 
		}
	}
	/*
	if (mn < num[0]) {
		res = V<int>(LN, 9);
		res[0] = num[0] - 1;
	}
	else {
		res = V<int>(LN);
		res[0] = num[0];
		for (int i = 0; i < LN; i ++) {
			int d = query(i, LN - 1);
			res[i] = d;
		}
	}
	*/
	return 0;
}
