#include <stdio.h>
#include <string.h>
#include <utility>
using namespace std;

const int MR = 20000, MW = 100;
int LR, LC, LW, ws[MW];
pair<int, int> dp[MR];
int main() {
	freopen("in", "r", stdin);
	scanf("%d %d %d", &LR, &LC, &LW);
	for (int c = 0; c < LW; c ++) {
		char tmp[10];
		scanf("%s", tmp);
		ws[c] = strlen(tmp);
	}
	for (int i = 0; i < LW; i ++) {
		int ct = i == LW - 1 && ws[i] <= LC? 1 : 0, cur = ws[i], ii = (i + 1) % LW;
		while (cur + ws[ii] + 1 <= LC) {
			cur += ws[ii] + 1;
			if (ii == LW - 1) {
				ct ++;
			}
			ii = (ii + 1) % LW;
		}
		dp[i] = {ct, ii};
	}
	int w = 0, ct = 0;
	for (int c = 0; c < LR; c ++) {
		ct += dp[w].first;
		w = dp[w].second;
	}

	printf("%d\n", ct);
	return 0;
}
