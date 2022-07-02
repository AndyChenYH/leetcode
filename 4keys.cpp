/*
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MN = 50;
int LN, dp[MN + 1];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &LN);
	for (int n = 0; n <= LN; n ++) {
		if (n == 0) {
			dp[n] = 0;
			continue;
		}
		dp[n] = dp[n - 1] + 1;
		for (int nn = 0; nn <= n - 3; nn ++) {
			dp[n] = max(dp[n], dp[nn] * (n - nn - 1));
		}
	}
	for (int n = 0; n <= LN; n ++) {
		printf("(%d,%d),", n, dp[n]);
	}
	printf("\n");
	return 0;
}
*/

//approach 2
//push dp: using current values to update future values

#include <stdio.h>
#include <algorithm>
using namespace std;

const int MN = 50, INF = 1e9 + 10;
int LN, dp[MN + 1];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &LN);
	for (int n = 0; n <= LN; n ++) {
		dp[n] = -INF;
	}
	for (int n = 0; n <= LN; n ++) {
		if (n <= 3) {
			dp[n] = n;
		}
		else {
			dp[n] = max(dp[n], dp[n - 1] + 1);
		}
		for (int nn = n + 3; nn <= LN; nn ++) {
			dp[nn] = max(dp[nn], dp[n] * (nn - n - 1));
		}
	}
	printf("%d\n", dp[LN]);
	return 0;
}
