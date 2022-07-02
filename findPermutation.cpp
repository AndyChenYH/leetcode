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

int LS, LN;
S sig;
int main() {
	sig = "DI";
	LS = sig.size();
	LN = LS + 1;
	int li = -1;
	V<int> res(LN);
	for (int i = 0; i < LN; i ++) {
		res[i] = i + 1;
	}
	for (int i = 1; i < LN; i ++) {
		if (sig[i - 1] == 'D') {
			if (li == -1) {
				li = i - 1;
			}
		}
		else {
			if (li != -1) {
				reverse(res.begin() + li, res.begin() + i);
				li = -1;
			}
		}
	}
	if (li != -1) {
		assert(sig[LS - 1] == 'D');
		reverse(res.begin() + li, res.end());
	}
	db(res);
	bt;
	return 0;
}
