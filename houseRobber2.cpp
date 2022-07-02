#include <stdio.h>
#include <algorithm>
using namespace std;

const int MN = 1000, INF = int(1e9 + 10);
int LN, arr[MN], dp[MN][2][2];
int main() {
	freopen("inp.in", "r", stdin);
	scanf("%d", &LN);
	for (int i = 0; i < LN; i ++) {
		scanf("%d", &arr[i]);
	}
	for (int e = 0; e < 2; e ++) {
		for (int i = LN - 1; 0 <= i; i --) {
			for (int p = 0; p < 2; p ++) {
				if (i == LN - 1) {
					dp[i][p][e] = p ? 0 : arr[i];
					continue;
				}
				int r1 = dp[i + 1][false][e];
				int r2 = p ? 0 : arr[i] + dp[i + 1][true][e];
				if (i == 0 && e) {
					dp[i][p][e] = r1;
					continue;
				}
				dp[i][p][e] = max(r1, r2);
			}
		}
	}
	printf("%d %d %d %d\n", dp[0][true][0], dp[0][false][0], dp[0][true][1], dp[0][false][0]);
	return 0;
}
