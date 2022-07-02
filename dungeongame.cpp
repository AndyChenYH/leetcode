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
V<V<int>> mb;

bool inbd(int i, int j) {
	return 0 <= i && i < NR && 0 <= j && j < NC;
}
int main() {
	ifstream fin("inp.in");
	fin >> NR >> NC;
	mb = V<V<int>>(NR, V<int>(NC));
	for (int cc = 0; cc < NR; cc ++) {
		for (int c = 0; c < NC; c ++) {
			fin >> mb[cc][c];
		}
	}
	V<V<int>> dp(NR, V<int>(NC));
	dp[0][0] = mb[0][0];
	for (int i = 1; i < NR; i ++) {
		dp[i][0] = dp[i - 1][0] + mb[i][0];
	}
	for (int j = 1; j < NC; j ++) {
		dp[0][j] = dp[0][j - 1] + mb[0][j];
	}
	for (int i = 1; i < NR; i ++) {
		for (int j = 1; j < NR; j ++) {
			int mn = INF;
			if (inbd(i - 1, j)) {
				mn = min(mn, dp[i - 1][j]);
			}
			if (inbd(i, j - 1)) {
				mn = min(mn, dp[i][j - 0]);
			}
			dp[i][j] = mn + mb[i][j];
		}
	}
	db(dp);
	return 0;
}
