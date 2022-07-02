#include <stdio.h>
#include <algorithm>
using namespace std;

const int MN = 2000, INF = 1e9 + 10;
int LR, LC, dp[MN][MN][4], psa[MN][MN][2];
char mb[MN][MN];
int main() {
	freopen("in", "r", stdin);
	scanf("%d %d", &LR, &LC);
	for (int i = 0; i < LR; i ++) {
		for (int j = 0; j < LC; j ++) {
			scanf(" %c", &mb[i][j]);
		}
	}

	for (int i = 0; i < LR; i ++) {
		dp[i][0][0] = 0;
		for (int j = 1; j < LC; j ++) {
			dp[i][j][0] = mb[i][j] == 'W' ? j : dp[i][j - 1][0];
		}
		dp[i][LC - 1][1] = LC - 1;
		for (int j = LC - 2; 0 <= j; j --) {
			dp[i][j][1] = mb[i][j] == 'W' ? j : dp[i][j + 1][1];
		}
	}
	for (int j = 0; j < LC; j ++) {
		dp[0][j][2] = 0;
		for (int i = 1; i < LR; i ++) {
			dp[i][j][2] = mb[i][j] == 'W' ? i : dp[i - 1][j][2];
		}
		dp[LR - 1][j][3] = LR - 1;
		for (int i = LR - 2; 0 <= i; i --) {
			dp[i][j][3] = mb[i][j] == 'W' ? i : dp[i + 1][j][3];
		}
	}
	for (int i = 0; i < LR; i ++) {
		psa[i][0][0] = mb[i][0];
		for (int j = 1; j < LC; j ++) {
			psa[i][j][0] = psa[i][j - 1][0] + mb[i][j] == 'E';
		}
	}
	for (int j = 0; j < LC; j ++) {
		psa[0][j][1] = mb[0][j];
		for (int i = 0; i < LR; i ++) {
			psa[i][j][1] = psa[i - 1][j][1] + mb[i][j] == 'E';
		}
	}
	int mx = -INF;
	for (int i = 0; i < LR; i ++) {
		for (int j = 0; j < LC; j ++) {
			if (mb[i][j] != '0') { continue; }
			int wl = dp[i][j][0];
			int wr = dp[i][j][1];
			int wd = dp[i][j][2];
			int wu = dp[i][j][3];
			int sm = psa[i][wr][0] - psa[i][wl][0] + (mb[i][wl] == 'E')
				+ psa[wd][j][1] - psa[wu][j][1] + (mb[wu][j] == 'E');
			
			mx = max(mx, sm);
		}
	}
	printf("%d\n", mx);
	return 0;
}
