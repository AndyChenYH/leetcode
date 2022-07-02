#include <bits/stdc++.h>
// #include "utils.cpp"
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

template <typename T>
struct hash<V<T>> {
    int operator () (V<T> v) const {
        ll r = 17;
        for (T d : v) {
            r = ((r * 31) % MOD + hash<T>()(d)) % MOD;
        }
        return int(r % MOD);
    }
    
};

int LN;
V<int> arr;
unordered_set<V<int>> res;
V<int> cur;
void sol(int ip) {
	res.insert(cur);
	for (int i = ip; i < LN; i ++) {
		cur.psb(arr[i]);
		sol(i + 1);
		cur.pop_back();
	}
}
V<V<int>> solve() {
	// arr = {1, 2, 3};
    sort(arr.begin(), arr.end());
	LN = arr.size();
	res = {};
	cur = {};
	sol(0);
	// db(res);
    V<V<int>> ret(res.begin(), res.end());
	return ret;
}


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        arr = nums;
        return solve();
    }
};
