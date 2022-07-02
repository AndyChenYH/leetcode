#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MS = 1000, INF = INT_MAX / 2;
int LS;
char s[MS + 1], tmp[MS + 1];
bool dp[MS + 1][MS + 1];
int main() {
	freopen("inp.in", "r", stdin);
	scanf("%s", s);
	LS = strlen(s);

	printf("%d\n", LS);
	int mx = -INF, mi = -1, mj = -1;
	for (int i = 0; i < LS; i ++) {
		for (int j = 0; j <= i; j ++) {
			if (i == j) {
				dp[i][j] = true;
				continue;
			}
			if (i - j == 1) {
				dp[i][j] = s[i] == s[j];
				continue;
			}
			dp[i][j] = s[i] == s[j] && dp[i - 1][j + 1];
		}
	}
	for (int i = 0; i < LS; i ++) {
		for (int j = 0; j <= i; j ++) {
			if (dp[i][j]) {
				if (mx < i - j + 1) {
					mx = i - j + 1, mi = i, mj = j;
				}
			}
		}
	}
	memcpy(tmp, s + mj, sizeof(char) * (mi - mj + 1));
	printf("%s\n", tmp);
	return 0;
}
