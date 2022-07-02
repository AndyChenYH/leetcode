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
#define tii trip<int, int, int>
#define ll long long
#define S string
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define MOD 1000000007
#define INF (2147483647 / 2)
#define printf(args...) fprintf(stderr, ##args)
using namespace std;

int NL;
V<int> arr;
int main() {
	arr = {0, 1,1,1,1,0,1,1};
	NL = arr.size();
	int L = 0, R = 0;
	int mx = -INF;
	while (R < NL) {
		if (arr[R] == 0) {
			L = R;
		}
		mx = max(mx, R - L);
		R ++;
	}
	db(mx);
	return 0;
}
