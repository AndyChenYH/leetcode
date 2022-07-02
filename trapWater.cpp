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
V<int> ele;
int main() {
	ele = {7, 0, 4, 0, 3, 0, 2, 0, 6, 0, 8, 0, 2};
	LN = ele.size();
	int tot = 0, blk = 0; 
	int li = 0, ri = 0;
	auto sol = [&] () -> void {
		while (ri < LN) {
			if (li == ri) {
				ri ++;
				continue;
			}
			if (ele[li] <= ele[ri]) {
				tot += (ri - li - 1) * ele[li] - blk;
				li = ri;
				blk = 0;
			}
			else {
				blk += ele[ri];
			}
			ri ++;
		}
	};
	sol();
	if (blk != 0) {
		ele = V<int>(ele.begin() + li, ele.begin() + ri);
		reverse(ele.begin(), ele.end());
		blk = 0;
		li = ri = 0;
		LN = ele.size();
		sol();
	}
	db(tot, blk, li, ri);
	return 0;
}
