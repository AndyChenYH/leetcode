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

const int MD = 100001;

int LN;
V<int> arr;
V<int> uf;
int main() {
	arr = {4, 6, 15, 35};
	LN = arr.size();
	uf = V<int>(LN);
	for (int u = 0; u < LN; u ++) {
		uf[u] = u;
	}
	unordered_map<int, int> occ = {};
	for (int i = 0; i < LN; i ++) {
		int d = arr[i];
		while (d < MD) {
			d += arr[i];
			if (occ.find(d) != occ.end()) {
				un(i, occ.at(d));
			}
		}
		occ.insert(d);
	}
	return 0;
}
