#include <bits/stdc++.h>
#include "utils.cpp"
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
#define INF INT_MAX
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	/*
	ifstream fin("inp.in");
	int NS;
	fin >> NS;
	V<V<bool>> mb(NS, V<bool>(NS, false));
	for (int cc = 0; cc < NS; cc ++) {
		for (int c = 0; c < NS; c ++) {
			bool hi;  fin >> hi;
			mb[cc][c] = hi;
		}
	}
	*/	
	int NS = 4;
	V<V<bool>> mb(NS, V<bool>(NS, false));
	V<V<bool>> tmpmb = mb;
	auto inbound = [&] (int ii, int jj) -> bool {
		return 0 <= ii && ii < NS && 0 <= jj && jj < NS;
	};
	auto canGo = [&] (int i, int j) -> bool {
		V<pii> dirs = {
			{-1, 1}, {0, 1}, {1, 1},
			{-1, 0}, {1, 0},
			{-1, -1}, {0, -1}, {1, -1},
		};
		for (pii dir : dirs) {
			int ni = i, nj = j;
			while (inbound(ni, nj)) {
				if (mb[ni][nj] == 1) { return false; }				
				ni += dir.fir;
				nj += dir.sec;
			}
		}
		assert(inbound(i, j));
		return true; 
	};
	int ct = 0;
	set<V<string>> res = {};
	F<bool(int)> sol = [&] (int nq) -> bool {
		db(mb);
		if (nq == NS) {
			ct ++;
			V<string> smb(NS);
			for (V<bool> row : mb) {
				string ln = "";
				for (bool d : row) {
					ln.push_back(d == 1 ? 'Q' : '.');
				}
				smb.push_back(ln);
			}
			res.insert(smb);
			return true;
		}
		for (int i = 0; i < NS; i ++) {
			for (int j = 0; j < NS; j ++) {
				if (canGo(i, j)) {
					mb[i][j] = true;
					if (!sol(nq + 1)) {
						mb[i][j] = false;
					}
				}
			}
		}
		return false;
	};
	sol(0);
	V<V<string>> ret = {};
	for (V<string> vs : res) { ret.push_back(vs); }
	db(ret);
	db(ct);
	return 0;
}
