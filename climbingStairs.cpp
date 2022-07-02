#include <stdio.h>

const int MN = 100000;
int LN, dp[MN + 1];
int main() {
	LN = 3;
	for (int n = 0; n <= LN; n ++) {
		if (n == 0) {
			dp[n] = 1;
			continue;
		}
		if (n == 1) {
			dp[n] = 1;
			continue;
		}
		if (n == 2) {
			dp[n] = 2;
			continue;
		}
		dp[n] = dp[n - 1] + dp[n - 2];
	}
	printf("%d\n", dp[LN]);
	return 0;
}
