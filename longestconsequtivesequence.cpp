#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define mkp make_pair
#define T tuple
#define mkt make_tuple
#define rep(act, x) for (int lolol = 0; lolol < x; lolol ++) { act; }
#define fir first
#define sec second
#define E exit(0)
#define F function
#define V vector
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define INF INT_MAX
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

V<int> lis = {100, 4, 200, 1, 3, 2};
int main() {
	int le = INF;
	int len = 0;
	int mxl = -INF;
	for (int d : lis) {
		db(len);
		if (le == INF || le + 1 != d) {
			mxl = max(mxl, len);
			len = 0;
		}
		le = d;
		len ++;
	}
	db(len);
	return 0;
}
