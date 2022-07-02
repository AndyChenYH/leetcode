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
#define mset multiset
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

int LS, LT;
S ss, t;
int main() {
	ss = "ADOBECODEBANC";
	t = "ABC";
	LS = ss.size(), LT = t.size();	
	map<char, int> occ = {};
	V<int> nd(128, 0);
	for (char c : t) {
		occ.insert({c, 0});
		nd[c] ++;
	}					
	int L = 0, R = 0;
	int mn = INF, ml = -1, mr = -1;
	
	db(nd);
	db(occ);
	while (R < LS) {
		if (find(t.begin(), t.end(), ss[R]) != t.end()) {
			occ.at(ss[R]) ++;
		}	
		bool yes = true;
		for (pair<char, int> pp : occ) {
			yes = yes && nd[pp.fi] <= pp.se;
		}
		if (yes) {
			while (true) {
				auto fii = occ.find(ss[L]);
				if (fii != occ.end()) {
					if (fii->se == nd[fii->fi]) {
						break;
					}
					else {
						fii->se --;
					}
				}
				L ++;
			}
			if (R - L < mn) {
				mn = R - L, ml = L, mr = R;
			}
		}
		R ++;
	}
	db(S(ss.begin() + ml, ss.begin() + mr + 1));
	return 0;
}
