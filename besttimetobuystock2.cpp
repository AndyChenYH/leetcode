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

int LN;
V<int> arr;
int main() {
	arr = {7, 6, 4, 3, 1};
	LN = arr.size();
	// 0: choosing b, 1: choosing s, 2: verifying sell
	int ss = 0;
	int b = -1, s = -1;
	int p = 0;
	for (int d : arr) {
		if (ss == 0) {
			b = d;
			ss = 1;
		}
		else if (ss == 1) {
			if (b < d) {
				s = d;
				ss = 2;
			}
			else {
				b = d;
			}
		}
		else if (ss == 2) {
			if (d <= s) {
				p += s - b;
				b = d;
				ss = 1;
			}
			else {
				s = d;
			}
		}
	}
	if (ss == 2) {
		p += s - b;
	}
	db(b, s, ss, p);
	return 0;
}
