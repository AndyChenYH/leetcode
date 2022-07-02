#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
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
#define dbl(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out_line(__VA_ARGS__)
#define INF INT_MAX / 2
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;


int main() {
	ifstream fin("inp.in");
	int NN, NE;
	fin >> NN >> NE;
	V<V<int>> lG(NN, V<int>(0));
	for (int cc = 0; cc < NE; cc ++) {
		int ca, cb;
		fin >> ca >> cb;
		lG[ca].push_back(cb);
	}
	db(plG(lG));
	stack<int> st;
	struct Vt {
		char vis;
		Vt() { 
			vis= 'w';
		}
	};
	V<Vt> vts(NN, Vt());
	st.push(0);
	while (true) {
L1:
		vts[st.top()].vis = 'b';
		bool hadj = false;
		for (int j : lG[st.top()]) {
			if (vts[j].vis == 'w') {
				hadj = true;
				db(j);
				vts[j].vis = 'b';
				st.push(j);
			}
		}
		if (!hadj) { st.pop(); }
		if (st.empty()) {
			for (int v = 0; v < NN; v ++) {
				if (vts[v].vis == 'w') {
					st.push(v);
					goto L1;
				}
			}
			break;
		}
	}	

	return 0;
}
