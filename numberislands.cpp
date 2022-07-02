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

int NR, NC;
V<V<bool>> mb;

int main() {
	ifstream fin("inp.in");
	fin >> NR >> NC;
	mb = V<V<bool>>(NR, V<bool>(NC));
	for (int cc = 0; cc < NR; cc ++) {
		string ln;  fin >> ln;
		for (int c = 0; c < NC; c ++) {
			mb[cc][c] = ln[c] - '0';
		}
	}
	auto canGo = [&] (int i, int j) -> bool {
		return 0 <= i && i < NR && 0 <= j && j < NC && mb[i][j] == 1;
	};
	int ict = 0;
	const V<pii> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	for (int i = 0; i < NR; i ++) {
		for (int j = 0; j < NC; j ++) {
			if (mb[i][j]) {
				ict ++;
				queue<pii> que;
				que.push({i, j});
				mb[i][j] = 0;
				while (true) {
					bool hadj = false;
					for (pii dir : dirs) {
						int ni = que.front().fir + dir.fir;
						int nj = que.front().sec + dir.sec;
						if (canGo(ni, nj)) {
							hadj = true;
							que.push({ni, nj});
							mb[ni][nj] = 0;
						}
					}
					if (!hadj) { que.pop(); }
					if (que.empty()) { break; }
				}
			}
		}
	}
	db(mb);
	db(ict);
}

