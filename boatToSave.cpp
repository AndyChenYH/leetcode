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

int LP, LM;
V<int> r_ps;
multiset<int, greater<int>> ps;
int main() {
	r_ps = {3, 5, 3, 4};
	LM = 5;
	LP = r_ps.size();
	for (int p : r_ps) {
		ps.insert(p);
	}
	int ct = 0;
	while (!ps.empty()) {
		int p = *ps.begin();
		ps.erase(ps.begin());
		int tar = LM - p;
		auto fii = ps.lower_bound(tar);
		db(p);
		if (fii != ps.end()) {
			db(*fii);
			ps.erase(fii);
		}
		ct ++;
	}
	db(ct);
	return 0;
}
