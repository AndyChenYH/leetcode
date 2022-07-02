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
V<pii> arr;
//[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
int main() {
	arr = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
	LN = arr.size();
	sort(arr.begin(), arr.end(), [&] (pii a, pii b) -> bool {
		if (a.fi == b.fi) {
			return a.se < b.se;
		}
		return a.fi > b.fi;
	});
	db(arr);
	V<pii> res = {};
	for (int i = 0; i < LN; i ++) {
		res.insert(res.begin() + arr[i].se, arr[i]);
	}
	db(res);
	V<V<int>> ret(LN);
	for (int i = 0; i < LN; i ++) {
		res[i] = {res[i].fi, res[i].se};
	}
	db(ret);
	return 0;
}
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]


