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

int NN, NE;
V<pii> eG;
V<int> rset;

int findd(int S) {
	if (rset[S] == S) {
		return S;
	}
	return findd(rset[S]);
}
void unionn(int A, int B) {
	int p1 = findd(A);
	int p2 = findd(B);
	rset[p1] = p2;
}
pii sol() {
	for (pii ed : eG) {
		if (findd(ed.fir) == findd(ed.sec)) {
			return ed;
		}
		unionn(ed.fir, ed.sec);
	}
	throw logic_error("hello world");
}
int main() {
	ifstream fin("inp.in");
	fin >> NE;
	eG = V<pii>(NE);
	NN = -INF;
	for (int cc = 0; cc < NE; cc ++) {
		int u, v;
		fin >> u >> v;
		u --;  v --;
		eG[cc].fir = u;
		eG[cc].sec = v;
		NN = max({NN, u, v});
	}
	NN ++;
	rset = V<int>(NN);
	for (int c = 0; c < NN; c ++) {
		rset[c] = c;
	}
	cerr << sol() << endl;
	return 0;
}
