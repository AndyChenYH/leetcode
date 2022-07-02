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
#define MN 10000

V<pii> eG;
int NN;
V<int> rset;
int findd(int S) {
	if (rset[S] == S) { return S; }
	return findd(rset[S]);
}
void unionn(int A, int B) {
	rset[findd(A)] = findd(B);
}
int main() {
	int NE;
	ifstream fin("inp.in");
	fin >> NE >> NN;
	eG = V<pii>(NE);
	for (int cc = 0; cc < NE; cc ++) {
		fin >> eG[cc].fir >> eG[cc].sec;
	}
	rset = V<int>(NN);
	for (int u = 0; u < NN; u ++) {
		rset[u] = u;
	}
	auto sol = [&] () -> bool {
		for (pii e : eG) {
			if (findd(e.fir) == findd(e.sec)) {
				db(e);
				return false;
			}
			unionn(e.fir, e.sec);
		}

		int cp = findd(0);
		for (int u = 1; u < NN; u ++) {
			if (findd(u) != cp) {
				return false;
			}
		}
		return true;
	};
	db(plG(rset));
	cerr << sol() << endl;
}
