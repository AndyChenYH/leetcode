#include <stdio.h>
#include <algorithm>
using namespace std;

const int MN = 100000;
int LN, cost[MN + 1], dp[MN + 1];
int main() {
	freopen("inp.in", "r", stdin);
	scanf("%d", &LN);
	for (int i = 0; i < LN; i ++) {
		scanf("%d", &cost[i]);
	}
	for (int i = 0; i <= LN; i ++) {
		if (i == 0 || i == 1) {
			dp[i] = 0;
			continue;
		}
		dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
	}
	for (int i = 0; i <= LN; i ++) {
		printf("%d: %d\n", i, dp[i]);
	}
	printf("\n");
	return 0;
}
