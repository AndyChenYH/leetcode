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
V<int> arr;
set<V<int>> res;
int main() {
	arr = {-4, -1, -1, 0, 0, 0, 1, 2};
	sort(arr.begin(), arr.end());
	db(arr);
	LN = arr.size();
	for (int i = 0; i < LN; i ++) {
		for (int j = i + 1; j < LN; j ++) {
			int g = 0 - (arr[i] + arr[j]);
			int o = lower_bound(arr.begin() + j + 1, arr.end(), g) - arr.begin();
			if (o != LN && arr[i] + arr[j] + arr[o] == 0) {
				V<int> r = {arr[i], arr[j], arr[o]};
				res.insert(r);
			}
		}
	}
	db(res);
	return 0;
}
