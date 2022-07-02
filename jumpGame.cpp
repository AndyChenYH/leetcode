#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

const int MN = 3e4;
int N, ar[MN], bit[MN];
int query(int i) {
	i ++;
	int sm = 0;
	while (0 < i) {
		sm += bit[i];
		i -= i & -i;
	}
	return sm;
}
void update(int i, int val) {
	i ++;
	while (i <= N) {
		bit[i] += val;
		i += i & -i;
	}
}
int range(int l, int r) {
	if (l == 0) { return query(r); }
	return query(r) - query(l - 1);
}
int main() {
	int t[] = {3, 2, 1, 0 ,4};
	N = sizeof(t) / sizeof(int);
	memcpy(ar, t, sizeof(t));
	memset(bit, 0, sizeof(bit));
	for (int i = N - 1; 0 <= i; i --) {
		bool yes;
		if (i == N - 1) {
			yes = true;
		}
		else {
			int l = i + 1, r = min(N - 1, i + ar[i]);
			yes = range(l, r) != 0;
		}
		update(i, yes);
	}
	printf("%d\n", query(0));
	return 0;
}
