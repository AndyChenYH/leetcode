#include <stdio.h>
#include <algorithm>
using namespace std;

const int MN = 1000, INF = int(1e9 + 10);
int LN, LK, cs[MN][MN], dp[MN][MN];
int main() {
	freopen("inp.in", "r", stdin);
	scanf("%d %d", &LN, &LK);
	for (int n = 0; n < LN; n ++) {
		for (int k = 0; k < LK; k ++) {
			scanf("%d", &cs[n][k]);
		}
	}
	for (int n = LN; 0 <= n; n --) {
		for (int p = 0; p < LK; p ++) {
			if (n == LN) {
				dp[n][p] = 0;
				continue;
			}
			int mn = INF;
			for (int c = 0; c < LK; c ++) {
				if (c == p) { continue; }
				mn = min(mn, cs[n][c] + dp[n + 1][c]);
			}
			dp[n][p] = mn;
		}
	}
	int mn = INF;
	for (int c = 0; c < LK; c ++) {
		mn = min(mn, dp[0][c]);
	}
	printf("%d\n", mn);
	return 0;
}
