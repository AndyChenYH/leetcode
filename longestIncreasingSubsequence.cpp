#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MN = 5000, INF = 1e9 + 10;
int N, ar[MN], bit[MN];
int query(int i) {
	i ++;
	int mx = -INF;
	while (0 < i) {
		mx = max(mx, bit[i]);
		i -= i & -i;
	}
	return mx;
}
void update(int i, int v) {
	i ++;
	while (i <= N) {
		bit[i] = max(bit[i], v);
		i += i & -i;
	}
}
int main() {
	int tmp[] = {10,9,2,5,3,7,101,18};
	N = sizeof(tmp) / sizeof(int);
	memcpy(ar, tmp, sizeof(tmp));
	sort(tmp, tmp + N);
	for (int i = 0; i < N; i ++) {
		int ii = lower_bound(tmp, tmp + N, ar[i]) - tmp;
		int r = query(ii) + 1;
		update(ii, r);
	}
	int mx = 0;
	for (int i = 0; i < N; i ++) {
		mx = max(mx, query(i));
	}
	printf("%d\n", mx);
	return 0;
}
