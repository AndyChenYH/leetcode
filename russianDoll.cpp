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

int LE;
V<pii> env;
map<int, int> mem;
int dp(int ei) {
	auto fii = mem.find(ei);
	if (fii != mem.end()) {
		return fii->se;
	}
	if (ei == 0) {
		return 1;
	}
	int mx = 0;
	for (int ii = 0; ii < ei; ii ++) {
		if (env[ii].fi < env[ei].fi && env[ii].se < env[ei].se) {
			mx = max(mx, dp(ii));
		}
	}

	int rr = mx + 1;
	mem.insert({ei, rr});
	return rr;
}
int solve() {
	mem = {};
	LE = env.size();
	sort(env.begin(), env.end(), [&] (pii a, pii b) -> bool {
		if (a.fi == b.fi) {
			return a.se < b.se;
		}
		return a.fi < b.fi;
	});
	int mx = -INF;
	for (int i = 0; i < LE; i ++) {
		mx = max(mx, dp(i));
	}
	return mx;
}


class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& r_env) {
        if (r_env.empty()) {
            return 0;
        }
        env = V<pii>((int) r_env.size());
        for (int i = 0; i < (int) r_env.size(); i ++) {
            env[i] = {r_env[i][0], r_env[i][1]};
        }
        return solve();
    }
};

int main() {
	Solution n;
	V<V<int>> r_inp = {{10,8},{1,12},{6,15},{2,18}};
	cerr << n.maxEnvelopes(r_inp) << endl;
	return 0;
}
