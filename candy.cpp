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
int main() {
	arr = {1, 3, 2, 2, 1};
	LN = arr.size();
	V<int> res(LN);
	int cur = 0;
	res[0] = 0;
	for (int i = 1; i < LN; i ++) {
		if (arr[i - 1] < arr[i]) {
			cur ++;
			res[i] = cur;
		}
		else if (arr[i] < arr[i - 1]) {
			if (cur <= 0) { cur --; }
			else { cur = 0; }
			res[i] = cur;
		}
		else {
			assert(arr[i] == arr[i - 1]);
			cur = 0;
			res[i] = cur;
		}
	}
	db(res);
	int mn = *min_element(res.begin(), res.end());
	if (mn < 1) {
		for (int &d : res) {
			d += 1 - mn;
		}
	}
	int sm = accumulate(res.begin(), res.end(), 0);
	db(res);
	db(sm);
	return 0;
}
