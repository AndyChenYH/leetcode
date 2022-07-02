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

int LS;
S ss;
int main() {
	ifstream fin("inp.in");
	fin >> ss;
	V<int> occ(128);
	for (char c : ss) {
		occ[c] ++;
	}
	LS = ss.size();
	sort(ss.begin(), ss.end(), [&] (char a, char b) -> bool { return occ[a] > occ[b]; });
	S res = "";
	V<bool> use(LS);
	res.psb(ss[0]);
	use[0] = true;
	for (int i = 1; i < LS; i ++) {
		for (int j = 0; j < LS; j ++) {
			if (use[j] || ss[j] == res.back()) { 
				continue; 
			}
			res.psb(ss[j]);
			use[j] = true;
			break;
		}
	}
	db(res);
	if (int(res.size()) < LS) {
		res = "";
	}
	return 0;
}
