#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;

const int MN = 1000, INF = 1e9 + 10;
int LR, LC, mb[MN][MN], dpr[MN][MN], dpc[MN][MN], dp[MN][MN];
int main() {
	freopen("in", "r", stdin);
	scanf("%d %d", &LR, &LC);
	for (int i = 0; i < LR; i ++) {
		for (int j = 0; j < LC; j ++) {
			scanf("%d", &mb[i][j]);
		}
	}
	for (int i = 0; i < LR; i ++) {
		for (int j = 0; j < LC; j ++) {
			if (j == 0) {
				dpr[i][j] = mb[i][j] == 1 ? 1 : 0;
				continue;
			}
			dpr[i][j] = mb[i][j] == 0 ? 0 : dpr[i][j - 1] + 1;
		}
	}

	for (int j = 0; j < LC; j ++) {
		for (int i = 0; i < LR; i ++) {
			if (i == 0) {
				dpc[i][j] = mb[i][j] == 1 ? 1 : 0;
				continue;
			}
			dpc[i][j] = mb[i][j] == 0 ? 0 : dpc[i - 1][j] + 1;
		}
	}
	for (int i = 0; i < LR; i ++) {
		for (int j = 0; j < LC; j ++) {
			if (mb[i][j] == 0) {
				dp[i][j] = 0;
				continue;
			}
			int r1 = j != 0 ? dpr[i][j - 1] : 0;
			int r2 = i != 0 ? dpc[i - 1][j] : 0;
			int r3 = i != 0 && j != 0 ? sqrt(dp[i - 1][j - 1]) : 0;
			dp[i][j] = pow(min(r1, min(r2, r3)) + 1, 2);
		}
	}
	int mx = -INF;
	for (int i = 0; i < LR; i ++) {
		for (int j = 0; j < LC; j ++) {
			mx = max(mx, dp[i][j]);
		}
	}
	printf("%d\n", mx);
	return 0;
}
