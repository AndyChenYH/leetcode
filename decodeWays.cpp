#include <stdio.h>
#include <algorithm>
using namespace std;

/*
 * dp[i] denotes the number of ways to decode 0..i
 * dp[0] = ar[0]
 * dp[1] = ar[0] * ar[1] + min(ar[0] * 10 + ar[1], 26)
 * dp[i] = dp[i - 1] * ar[i] + min(ar[i - 1] * 10 + ar[i], 26);
*/

const int MN = 1000;
int LN, ar[MN], dp[MN];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &LN);
	for (int i = 0; i < LN; i ++) {
		scanf("%d", &ar[i]);
	}
	for (int i = 0; i < LN; i ++) {
		int a = 1 <= ar[i] && ar[i] <= 9;
		if (i == 0) {
			dp[i] = a;
            continue;
		}
        int d = ar[i - 1] * 10 + ar[i];
		int b = 10 <= d && d <= 26;
		if (i == 1) {
			dp[i] = a * dp[i - 1] + b;
            continue;
		}
        int r1 = a * dp[i - 1];
        int r2 = b * dp[i - 2];
        dp[i] = r1 + r2;

	}
	printf("%d\n", dp[1]);
	return 0;
}
