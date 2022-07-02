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

int LN;
int tar;
V<int> r_arr;
V<pii> arr;
int main() {
	tar = 6;
	r_arr =  {3, 2, 4};
	LN = r_arr.size();
	arr = V<pii>(LN);
	for (int i = 0; i < LN; i ++) {
		arr[i] = {r_arr[i], i};
	}
	sort(arr.begin(), arr.end(), [&] (pii a, pii b) -> bool { return a.fi < b.fi; });
	db(arr);
	auto sol = [&] () -> pii {
		for (int i = 0; i < LN; i ++) {
			auto cmp = [&] (pii a, int b) -> bool { return a.fi < b; };
			int o = lower_bound(arr.begin(), arr.end(), tar - arr[i].fi, cmp) - arr.begin();
			if (o != LN && o != i && arr[o].fi + arr[i].fi == tar) {
				return {arr[i].se, arr[o].se};
				break;
			}	
		}	
		return {-1, -1};
	};
	pii rr = sol();
	db(rr);
	return 0;
}
