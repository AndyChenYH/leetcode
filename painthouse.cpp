#include <stdio.h>
#include <algorithm>
using namespace std;

const int MN = 1000, INF = int(1e9 + 1e8);
int LN, cs[MN][3], dp[MN + 1][3];
int main() {
	freopen("inp.in", "r", stdin);
	scanf("%d", &LN);
	for (int i = 0; i < LN; i ++) {
		for (int c = 0; c < 3; c ++) {
			scanf("%d", &cs[i][c]);
		}
	}
	for (int i = LN - 1; 0 <= i; i --) {
		for (int pc = 0; pc < 3; pc ++) {
			if (i == LN - 1) {
				dp[i][pc] = min(cs[i][(pc + 1) % 3], cs[i][(pc + 2) % 3]);
				continue;
			}
			int mn = INF;
			for (int c = 0; c < 3; c ++) {
				if (c != pc) {
					mn = min(mn, cs[i][c] + dp[i + 1][c]);
				}
			}
			dp[i][pc] = mn;
		}
	}
	printf("%d\n", min(dp[0][0], min(dp[0][1], dp[0][2])));
	return 0;
}
