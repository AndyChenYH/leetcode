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
#define printf(args...) fprintf(stderr, ##args)
#define INF (2147483647 / 2)
using namespace std;

int LS;
S ss;
int sol() {
//	ss = "caabbbc";
	LS = ss.size();
	int L = 0, R = 0;
	map<char, int> occ = {};
	int mx = -INF;
	while (R < LS) {
		auto fii = occ.find(ss[R]);
		if (fii != occ.end()) {
			fii->se ++;
		}
		else {
			if (occ.size() == 2) {
				occ.at(ss[L]) --;
				while (occ.at(ss[L]) != 0) {
					L ++;
					occ.at(ss[L]) --;
				}
				occ.erase(occ.find(ss[L]));
				L ++;
			}
			occ.insert({ss[R], 1});	
		}			
		mx = max(mx, R - L);
		R ++;
	}
	mx ++;
	return mx;
}
int main() {
	while (true) {
		bt;
		cin >> ss;
		db(sol());
	}
	return 0;
}


