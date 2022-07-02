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

ll LN;
V<pair<ll, ll>> its;
int main() {
	its = {{0, 9}, {1, 6}, {1, 8}, {6, 9}, {6, 11}, {7, 8}, {7, 10}, {7, 13}, {9, 13}, {9, 16}};
	sort(its.begin(), its.end());
	its.psb({LONG_MAX - 1, LONG_MAX});
	LN = its.size();
	db(its);	
	int ct = 0;
	auto cmp = [&] (pair<ll, ll> a, pair<ll, ll> b) -> bool { return a.se < b.se; };
	multiset<pair<ll, ll>, decltype(cmp)> win(cmp);
	for (pair<ll, ll> pp : its) {
		win.insert(pp);
		db(pp, win);
		if (win.begin()->se < pp.fi) {
			ll p = win.begin()->se;
//			db(p, pp, win);
			while (!win.empty() && win.begin()->fi <= p) {
				win.erase(win.begin());
			}
			ct ++;
		}
	}
	db(ct);
	return 0;
}
