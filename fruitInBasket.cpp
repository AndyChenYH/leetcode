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

int LN;
V<int> ts;
int main() {
	ts = {1, 2, 1};
	LN = ts.size();
	int li = 0, ri = 0;
	unordered_map<int, int> mp = {};
	int mx = -1e9;
	while (ri < LN) {
		if (mp.find(ts[ri]) != mp.end()) {
			mp.at(ts[ri]) ++;
		}
		else {
			mp.insert({ts[ri], 1});
		}
		if (2 < mp.size()) {
			while (2 < mp.size()) {
				mp.at(ts[li]) --;
				if (mp.at(ts[li]) == 0) {
					mp.erase(mp.find(ts[li]));
				}
				li ++;
			}
		}
		mx = max(mx, ri - li + 1);
		ri ++;
	}
	db(mx);
	return 0;
}
