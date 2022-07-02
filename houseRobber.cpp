#include <stdio.h>
#include <algorithm>
using namespace std;

const int MN = 5000, INF = int(1e9 + 1e8);
int LN, arr[MN], dp[MN][2];
int main() {
	freopen("inp.in", "r", stdin);
	scanf("%d", &LN);
	for (int i = 0; i < LN; i ++) {
		scanf("%d", &arr[i]);
	}
	for (int i = LN - 1; 0 <= i; i --) {
		for (int p = 0; p < 2; p ++) {
			if (i == LN - 1) {
				dp[i][p] = p ? 0 : arr[i];
				continue;
			}
			dp[i][p] = dp[i + 1][false];
			if (!p) {
				dp[i][p] = max(dp[i][p], arr[i] + dp[i + 1][true]);
			}
		}
	}
	printf("%d\n", max(dp[0][true], dp[0][false]));
	return 0;
}
