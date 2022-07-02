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
V<tiii> uf;
int fid(int a) {
	if (get<0>(uf[a]) == a) {
		return a;
	}
	else {
		int rt = fid(get<0>(uf[a]));
		get<0>(uf[a]) = rt;
		return rt;
	}
}
void un(int a, int b) {
	int pa = fid(a);
	int pb = fid(b);
	int lb = min(get<1>(uf[pa]), get<1>(uf[pb]));
	int ub = max(get<2>(uf[pa]), get<2>(uf[pb]));
	get<1>(uf[pb]) = lb;
	get<2>(uf[pb]) = ub;

	get<0>(uf[pa]) = pb;
}
int main() {
	//     0    1  2    3  4  5
	arr = {50, 10, 1, 4, 5, 3, 2, 8, 7, 6};
	LN = arr.size();
	uf = V<tiii>(LN);
	for (int a = 0; a < LN; a ++) {
		uf[a] = {a, arr[a], arr[a]};
	}
	unordered_map<int, int> occ = {};
	for (int i = 0; i < LN; i ++) {
		auto f1 = occ.find(arr[i] - 1);
		if (f1 != occ.end()) {
			un(i, f1->se);
		}
		auto f2 = occ.find(arr[i] + 1);
		if (f2 != occ.end()) {
			un(i, f2->se);
		}
		occ.insert({arr[i], i});
	}
	db(plG(uf));
	int mx = -INF;
	for (tiii t : uf) {
		mx = max(mx, get<2>(t) - get<1>(t) + 1);
	}
	db(mx);
	return 0;
}
