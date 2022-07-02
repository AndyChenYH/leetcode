#include <stdio.h>

const int MN = 10000;
int LN, ar[MN];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &LN);
	for (int i = 0; i < LN; i ++) {
		scanf("%d", &ar[i]);
	}
	bool use = false, yes = true;
	for (int i = 0; i < LN - 1; i ++) {
		if (ar[i + 1] < ar[i]) {
			if (use) { 
				yes = false; 
				break;
			}
			else {
				use = true;
				bool r = i == 0 || ar[i - 1] <= ar[i + 1] || i + 1 == LN - 1 || ar[i] <= ar[i + 2];
				if (!r) {
					yes = false;
					break;
				}
			}
		}
	}
	printf("%d\n", yes);
}
