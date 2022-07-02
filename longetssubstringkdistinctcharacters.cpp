#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define psb push_back
#define tup tuple
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define E exit(0)
#define F function
#define V vector
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define pt(...) pt_out(__VA_ARGS__)
#define INF INT_MAX / 2
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

#define MN 128
int Nk, NL;
string ss;
int main() {
	ifstream fin("inp.in");
	fin >> ss >> Nk;
	NL = ss.size();
	bool occ[MN];
	fill(occ, occ + MN, 0);
	int i = 0, ii = 0;
	int mx = -INF;
	while (i != NL && ii != NL) {
		if (!occ[(int)ss[ii]]) { // extend
			occ[ii] = 1;
			if (Nk <= ii - i + 1) {
				mx = max(mx, ii - i + 1);
			}
			ii ++;
		}
		else { // shrink
			occ[(int)ss[i]] = 0;
			i ++;
		}
	}
	db(mx);
}
