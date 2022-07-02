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

int NR, NC;
V<V<int>> mb;
V<V<pii>> rset;
pii findd(pii S) {
	if (rset[S.fir][S.sec] == S) {
		return S;
	}
	return findd(rset[S.fir][S.sec]);
}
void unionn(pii A, pii B) {
	pii pr1 = findd(A);
	pii pr2 = findd(B);
	rset[pr1.fir][pr1.sec] = pr2;
}
int main() {
	ifstream fin("inp.in");
	fin >> NR >> NC;
	mb = V<V<int>>(NR, V<int>(NC));
	rset = V<V<pii>>(NR, V<pii>(NC));
	for (int cc = 0; cc < NR; cc ++) {
		string ln;
		fin >> ln;
		for (int c = 0; c < NC; c ++) {
			mb[cc][c] = ln[c] - '0';
			rset[cc][c] = {cc, c};
		}
	}
	const V<pii> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	auto canGo = [&] (int i, int j) -> bool {
		return 0 <= i && i < NR && 0 <= j && j < NC && mb[i][j] == 1;
	};
	for (int i = 0; i < NR; i ++) {
		for (int j = 0; j < NC; j ++) {
			if (mb[i][j] == 1) {
				for (pii dir : dirs) {
					int ni = i + dir.fir;
					int nj = j + dir.sec;
					if (canGo(ni, nj)) {
						unionn({i, j}, {ni, nj});
					}
				}
			}
		}
	}
	set<pii> res = {};
	for (int i = 0; i < NR; i ++) {
		for (int j = 0; j < NC; j ++) {
			if (mb[i][j] == 1) {
				res.insert(findd(rset[i][j]));
			}
		}
	}
	db(rset, mb, res);
	return 0;
}
