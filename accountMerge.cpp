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

struct Vt {
	string nm;
	V<string> mails;
	Vt() {};
	Vt(string n, string m) {
		nm = n;
		mails[0]= m;
	}
};
ostream& operator << (ostream& out, Vt v) {
	out << v.nm << " " << v.mails << endl;
	return out;
}
int NN;
V<V<string>> acts;
V<Vt> vts;
V<int> rset;
V<V<int>> lG;
int findd(int S) {
	if (rset[S] == S) { return S; }
	return findd(rset[S]);
}
void unionn(int A, int B) {
	int p1 = findd(A);
	int p2 = findd(B);
	rset[p1] = p2;
}
int main() {
	acts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, 
		{"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
	NN = 0;
	for (V<string> ac : acts) {
		string nm = ac[0];
		for (int i = 1; i < (int) ac.size(); i ++) {
			vts.psb(Vt(nm, ac[i]));
			NN ++;
		}
	}
	lG = V<V<int>>(NN, V<int>(0));
	rset = V<int>(NN);
	for (int v = 0; v < NN; v ++) { rset[v] = v; }
	int nn = 0;
	for (V<string> ac : acts) {
		string nm = ac[0];
		for (int i = 1; i < (int) ac.size(); i ++) {
			lG[nn].psb(nn + 1);
			nn ++;
		}
	}
	db(NN, vts);
	for (int u = 0; u < NN; u ++) {
		for (int v = 0; v < NN; v ++) {
			if (u == v) { continue; }
			if (vts[u].mails[0] == vts[v].mails[0]) {
				unionn(u, v);
			}
		}
	}
	bt;
	for (int u = 0; u < NN; u ++) {
		for (int v = 0; v < NN; v ++) {
			if (u == v ) { continue; }
			if (findd(u) == findd(v)) {
				for (string m : vts[v].mails) {
					vts[u].mails.psb(m);
				}
			}
		}
	}
	bt;
	db(vts);
	db(rset);
}
