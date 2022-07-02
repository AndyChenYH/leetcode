#include <stdio.h>
#include <numeric>
using namespace std;

const int ME = 100, MN = 200;
int LN, ar[MN];
bool dp[MN][ME * MN + 1];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &LN);
	for (int i = 0; i < LN; i ++) scanf("%d", &ar[i]);
	int sm = accumulate(ar, ar + LN, 0);
	for (int i = 0; i < LN; i ++) {
		for (int a = ME * MN + 1; 0 <= a; a--) {
			if (i == 0) {
				dp[i][a] = a * 2 == sm;
				continue;
			}
			int r1 = dp[i - 1][a];
			int r2 = a + ar[i] <= sm ? dp[i - 1][a + ar[i]] : false;
			dp[i][a] = r1 || r2;

		}
	}
	printf("%d\n", dp[LN - 1][0]);
	return 0;
}
