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
#define mset multiset
#define mmap multimap
#define pii pair<int, int>
#define tiii trip<int, int, int>
#define ll long long
#define S string
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define MOD 1000000007
#define INF (2147483647 / 2)
#define printf(args...) fprintf(stderr, ##args)
using namespace std;

/*
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
*/
V<V<int>> tri;
int main() {
	tri = {
		{2},
		{3, 4},
		{6, 5, 7},
		{4, 1, 8, 3},
	};
	map<pii, int> mem = {};
	F<int(int, int)> dp = [&] (int i, int j) -> int {
		auto fii = mem.find({i, j});
		if (fii != mem.end()) {
			return fii->se;
		}
		if (i == int(tri.size()) - 1) {
			return tri[i][j];
		}
		int a = dp(i + 1, j);
		int b = dp(i + 1, j + 1);
		int res = min(a, b) + tri[i][j];
		mem.insert({{i, j}, res});
		return res;
	};
	int rr = dp(0, 0);
	db(mem);
	db(rr);	
}
