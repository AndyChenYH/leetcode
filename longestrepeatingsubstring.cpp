#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define psb push_back
#define mkp make_pair
#define mkt make_trip
#define fir first
#define sec second
#define thi third
#define E exit(0)
#define F function
#define V vector
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define MOD 1000000007
#define printf(args...) fprintf(stderr, ##args)
#define INF (2147483647 / 2)
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef string S;

string ss;
int NL;
int main() {
	ss = "bbbbb";
	NL = ss.size();
	V<bool> occ(128, 0);
	int i = 0, ii = 0;
	int mx = -INF;
	while (ii < NL) {
		if (occ[ss[ii]]) {
			while (ss[i] != ss[ii]) {
				occ[ss[i]] = 0;
				i ++;
			}
			i ++;
		}
		occ[ss[ii]] = 1;
		ii ++;
		mx = max(mx, ii - i);
	}
	db(mx);
	return 0;
}
