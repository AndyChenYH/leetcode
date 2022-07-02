#include <stdio.h>
#include <algorithm>
using namespace std;

const int MN = 10000, INF = 1e9 + 10;
int LN, ar[MN], dp[MN][2];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &LN);
	for (int i = 0; i < LN; i ++) {
		scanf("%d", &ar[i]);
	}
	for (int i = 0; i < LN; i ++) {
		if (i == 0) {
			dp[i][0] = dp[i][1] = ar[i];
			continue;
		}
		int r1 = dp[i - 1][0] * ar[i], r2 = dp[i - 1][1] * ar[i];
		dp[i][0] = min(ar[i], min(r1, r2));
		dp[i][1] = max(ar[i], max(r1, r2));
	}
	
	for (int i = 0; i < LN; i ++) {
		printf("%d %d\n", dp[i][0], dp[i][1]);
	}
	return 0;
}
