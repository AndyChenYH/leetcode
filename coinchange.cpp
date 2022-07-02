#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;

const int MN = 100000, MM = 100000, INF = INT_MAX / 2;
int LN, LM, arr[MN + 1], dp[MM + 1];
int main() {
	freopen("inp.in", "r", stdin);
	scanf("%d %d", &LN, &LM);
	for (int i = 0; i < LN; i ++) {
		scanf("%d", &arr[i]);
	}
	for (int m = 0; m <= LM; m ++) {
		if (m == 0) {
			dp[m] = 0;
			continue;
		}
		dp[m] = INF;
		for (int i = 0; i < LN; i ++) {
			if (0 <= m - arr[i]) {
				dp[m] = min(dp[m], 1 + dp[m - arr[i]]);
			}
		}
	}
	printf("%d\n", dp[LM]);
	return 0;
}
