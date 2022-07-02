#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define psb push_back
#define mkp make_pair
#define mkt make_tuple
#define fi first
#define se second
#define T tuple
#define E exit(0)
#define F function
#define V vector
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ll long long
#define S string
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define MOD int(1e9 + 7)
#define INF (INT_MAX / 2)
using namespace std;

int LA, LC;
V<int> arr;
V<int> cs;
int main() {
	arr = {4, 2, 7};
	cs = {2, 4, 3};
	LA = arr.size(), LC = cs.size();
	sort(arr.begin(), arr.end());
	sort(cs.begin(), cs.end());
	int i1 = 0, i2 = 0;
	int ct = 0;
	while (i1 < LA && i2 < LC) {
		if (arr[i1] <= cs[i2]) {
			i1 ++, i2 ++;
			ct ++;
		}
		else {
			i2 ++;
		}
	}
	db(ct);
	return 0;
}
