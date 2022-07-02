#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define psb push_back
#define mkp make_pair
#define mkt make_tuple
#define fi first
#define se second
#define T tuple
#define F function
#define S string
#define V vector
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ll long long
#define E exit(0)
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define MOD int(1e9 + 7)
#define INF (INT_MAX / 2)
using namespace std;

int LN;
V<int> arr;
V<V<int>> mem;
int dp(int ind, bool pos) {
	if (ind == 0) {
		return 1;
	}
	if (mem[ind][pos] != -1) {
		return mem[ind][pos];
	}
	int diff = arr[ind] - arr[ind - 1];
	bool pp = 0 < diff;
	int res;
	if (diff == 0 || pp != pos) {
		res = dp(ind - 1, pos);
	}
	else {
		res = 1 + dp(ind - 1, !pos);
	}
	mem[ind][pos] = res;
	return res;
}
int main() {
	arr = {1,17,5,10,13,15,10,5,16,8};
	LN = arr.size();
	mem = V<V<int>>(LN, V<int>(2, -1));
	int r1 = dp(LN - 1, true);
	int r2 = dp(LN - 1, false);
	int rr = max(r1, r2);
	db(rr);
	return 0;
}
