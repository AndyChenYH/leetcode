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
V<int> arr;
unordered_map<pii, int> mem;
int dp(int i, int j) {
	if (mem.find({i, j}) != mem.end()) { return mem.at({i, j}); }
	int val = 0;
	if (i != 0) {
		val += abs(arr[i - 1] - arr[j]) - abs(arr[i - 1] - arr[i]);	
	}
	if (j != LN - 1) {
		val += abs(arr[j + 1] - arr[i]) - abs(arr[j + 1] - arr[j]);
	}
	if (i == j) { return val; }
	int a = dp(i + 1, j);
	int b = dp(i, j - 1);

	int r = max(val, max(a, b));
	mem.insert({{i, j}, r});
	return r;
}
int main() {
	arr = {2, 4, 9, 24, 2, 1, 10};
	LN = arr.size();
	mem = {};
	int sm = 0;
	for (int i = 0; i < LN - 1; i ++) {
		sm += abs(arr[i + 1] - arr[i]);
	}
	int r = dp(0, LN - 1);
	sm += r;
	db(sm);
	return 0;
}
