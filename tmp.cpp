#include <bits/stdc++.h>
// #include "utils.cpp"
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
V<int> hs;
V<V<V<int>>> mem;
int dp(int ind, bool ok, bool use) {
	if (mem[ind][ok][use] != -1) {
		return mem[ind][ok][use];
	}
	if (ind == 0) {
		if (use) {
			return 0;
		}
		else {
			if (ok) {
				return hs[ind];
			}
			else {
				return 0;
			}
		}
	}
	int mx = -INF;
	if (ok) {
		mx = max(mx, hs[ind] + dp(ind - 1, false, use));
	}
	mx = max(mx, dp(ind - 1, true, use));
	mem[ind][ok][use] = mx;
	return mx;
}
int solve() {
	// hs = {1, 2, 3, 4, 5};
	LN = hs.size();
    if (LN == 0) {
        return 0;
    }
    else if (LN == 1) {
        return hs[0];
    }
    else if (LN == 2) {
        return max(hs[0], hs[1]);
    }
	mem = V<V<V<int>>>(LN, V<V<int>>(2, V<int>(2, -1)));
	int rr = max(dp(LN - 1, true, true), dp(LN - 2, true, false));
	return rr;
}


class Solution {
public:
    int rob(vector<int>& nums) {
        hs = nums;
        return solve();
    }
};
