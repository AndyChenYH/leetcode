#include <stdio.h>
#include <algorithm>
using namespace std;

const int MN = 1000, INF = int(1e9 + 10);
int N, dp[MN + 1][MN + 1];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &N);
	for (int n = N; 0 <= n; n --) {
		for (int c = N; 0 <= c; c --) {
		if (n == N) {
			dp[n][c] = 0;
			continue;
		}
		int r1 = n + c <= N && c != 0 ? 1 + dp[n + c][c] : INF;
		int r2 = n + n <= N ? 2 + dp[n + n][n] : INF;
		dp[n][c] = min(r1, r2);
		}
	}
	printf("%d\n", dp[1][0]);
	return 0;
}
