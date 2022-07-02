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
V<int> arr;
int main() {
	tar = 5;
	arr = {1, 2, 3, 4, 5};
	LN = arr.size();
	int li = 0, ri = 0;
	int win = 0;
	int ct = 0;
	while (ri < LN) {
		win += arr[ri];
		db(win, li, ri);
		if (win == tar) {
			ct ++;
		}
		if (tar < win) {
			win -= arr[li];
			li ++;
		}
		ri ++;
	}	
	db(ct);
	return 0;
}
