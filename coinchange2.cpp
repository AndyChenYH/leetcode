#include <stdio.h>

const int MN = 500, MM = 5000;
int LN, LM, arr[MN + 1], dp[MN + 1][MM + 1];
int main() {
	freopen("inp.in", "r", stdin);
	scanf("%d %d", &LN, &LM);
	for (int i = 0; i < LN; i ++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < LN; i ++) {
		for (int m = 0; m <= LM; m ++) {
			if (m == 0) {
				dp[i][m] = 1;
				continue;
			}
			dp[i][m] = 0;
			for (int c = 0; c <= i; c ++) {
				if (0 <= m - arr[c]) {
					dp[i][m] += dp[c][m - arr[c]];
				}
			}
		}
	}
	printf("%d\n", dp[LN - 1][LM]);
	return 0;
}
