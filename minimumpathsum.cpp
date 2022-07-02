#include <bits/stdc++.h>
#include "utils.cpp"
#define pqueue priority_queue
#define itr iterator
#define mkp make_pair
#define T tuple
#define mkt make_tuple
#define rep(act, x) for (int lolol = 0; lolol < x; lolol ++) { act; }
#define fir first
#define sec second
#define E exit(0)
#define F function
#define V vector
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dbl(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out_line(__VA_ARGS__)
#define INF INT_MAX
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int NR, NC;
V<V<int>> mb;

struct Vt {
	int i, j, cs, pr;
	Vt() {};
	Vt (int ii, int jj) {
		i = ii;
		j = jj;
		cs = INF;
		pr = -1;
	}
};
ostream& operator << (ostream& out, Vt v) {
	string tmp = v.cs == INF ? "INF" : to_string(v.cs);
	out << v.i << " " << v.j << " " << tmp << " " << v.pr;
	return out;
}

int main() {
	ifstream fin("inp.in");
	fin >> NR >> NC;
	mb = V<V<int>>(NR, V<int>(NC));
	V<Vt> vts(NR * NC);
	int NN = 0;
	int si = 1, sj = 1, di = NR - 1, dj = NC - 1;
	V<V<int>> ncs(NR, V<int>(NC));
	for (int cc = 0; cc < NR; cc ++) {
		for (int c = 0; c < NC; c ++) {
			fin >> mb[cc][c];
			vts[NN] = Vt(cc, c);
			ncs[cc][c] = NN;
			NN ++;
		}
	}

	int src = ncs[si][sj], dest = ncs[di][dj];
	vts[src].cs = 0;
	db(vts);
	auto comp = [&] (int u, int v) -> bool { return vts[u].cs > vts[v].cs; };
	V<int> spt;  spt.reserve(NN);
	pqueue<int, V<int>, decltype(comp)> out(comp);
	for (int v = 0; v < NN; v ++) {
		out.push(v);
	}
	const V<pii> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	auto canGo = [&] (int i, int j) -> bool {
		return 0 <= i && i < NR && 0 <= j && j < NC;
	};
	while (!out.empty()) {
		db(vts);
		for (pii dir : dirs) {
			int ni = vts[out.top()].i + dir.fir;
			int nj = vts[out.top()].j + dir.sec;
			if (canGo(ni, nj)) {
				int nd = ncs[ni][nj];
				int nc = vts[out.top()].cs + 1;
				if (nc < vts[nd].cs) {
					vts[nd].cs = nc;
					vts[nd].pr = out.top();
				}
			}
		}
		spt.push_back(out.top());
		out.pop();
	}
	E;
	db(ncs);
	db(vts);
}
