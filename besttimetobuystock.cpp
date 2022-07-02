#include <stdio.h>
#include <algorithm>
using namespace std;

const int MN = 10000, INF = 1e9 + 10;
int LN, ar[MN], rmq[MN];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &LN);
	for (int i = 0; i < LN; i ++) {
		scanf("%d", &ar[i]);
	}
	rmq[0] = ar[0];
	for (int i = 1; i < LN; i ++) {
		rmq[i] = min(ar[i], rmq[i - 1]);
	}
	int mx = 0;
	for (int i = 1; i < LN; i ++) {
		mx = max(mx, ar[i] - rmq[i - 1]);
	}
	printf("%d\n", mx);
	return 0;
}
