#include <stdio.h>
#include <algorithm>
using namespace std;

/*
 * dp[i][j] denotes min path from (i, j) to (LN - 1, LM - 1)
 * dp[LN - 1][LM - 1] = mb[i][j];
 * dp[i][j] = mb[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
*/
const int MN = 2000, INF = 1e9 + 10;
int LN, LM, mb[MN][MN], dp[MN][MN];
int main() {
	freopen("in", "r", stdin);
	scanf("%d %d", &LN, &LM);
	for (int i = 0; i < LN; i ++) {
		for (int j = 0; j < LM; j ++) {
			scanf("%d", &mb[i][j]);
		}
	}

	for (int i = LN - 1; 0 <= i; i --) {
		for (int j = LM - 1; 0 <= j; j --) {
			if (i == LN - 1 && j == LM - 1) {
				dp[i][j] = mb[i][j];
				continue;
			}
			int r1 = i != LN - 1 ? dp[i + 1][j] : INF;
			int r2 = j != LM - 1 ? dp[i][j + 1] : INF;
			dp[i][j] = mb[i][j] + min(r1, r2);
		}
	}
	printf("%d\n", dp[0][0]);
	return 0;
}
