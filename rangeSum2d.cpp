#include <stdio.h>

const int MN = 2000;
int LR, LC, mb[MN][MN], dp[MN][MN];
int query(int i1, int j1, int i2, int j2) {
	int t = i1 != 0 ? dp[i1 - 1][j2] : 0;
	int l = j1 != 0 ? dp[i2][j1 - 1] : 0;
	int c = i1 != 0 && j1 != 0 ? dp[i1 - 1][j1 - 1] : 0;
	return dp[i2][j2] - t - l + c;
}
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
			if (i == 0 && j == 0) {
				dp[i][j] = mb[i][j];
			}
			else if (i == 0) {
				dp[i][j] = dp[i][j - 1] + mb[i][j];
			}
			else if (j == 0) {
				dp[i][j] = dp[i - 1][j] + mb[i][j];
			}
			else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mb[i][j];
			}
		}
	}
	printf("%d\n", query(1, 0, 2, 2));
	return 0;
}
