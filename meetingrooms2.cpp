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
V<pii> tms;
int main() {
	tms = {{1, 13}, {13, 15}};
	LN = tms.size();
	sort(tms.begin(), tms.end());
	int L = 0;
	int mx = -INF, cur = 0;
	auto cmp = [&] (pii a, pii b) -> bool { return a.se < b.se; };
	set<pii, decltype(cmp)> win(cmp);
	for (pii pp : tms) {
		win.insert(pp);
		cur ++;
		L = pp.fi;
		while (win.begin()->se <= L) { 
			win.erase(win.begin()); 
			cur --;
		}
		db(cur, L, win);
		mx = max(mx, cur);
	}
	db(mx);
	return 0;
}


