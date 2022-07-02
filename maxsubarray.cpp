#include <stdio.h>
#include <algorithm>
using namespace std;

const int MN = 1000, INF = int(1e9 + 1e8);
int LN, arr[MN], dp[MN];
int main() {
	freopen("inp.in", "r", stdin);
	scanf("%d", &LN);
	for (int i = 0; i < LN; i ++) {
		scanf("%d", &arr[i]);
	}
	dp[0] = arr[0];
	for (int i = 0; i < LN; i ++) {
		dp[i] = max(dp[i - 1] + arr[i], max(0, arr[i]));
	}
	int mx = -INF;
	for (int i = 0; i < LN; i ++) {
		mx = max(mx, dp[i]);
	}
	printf("%d\n", mx);
	return 0;
}
