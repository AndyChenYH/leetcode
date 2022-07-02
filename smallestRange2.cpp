#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 10, MN = 1e4;
int N, K, A[MN];
int smallestRangeII() {
	sort(A, A + N);
	for (int i = 0; i < N; i ++) {
		printf("%d ", A[i]);
	}
	puts("");
	if (N == 1) { return 0; }
	else {
		int a = A[N - 1] - K, b = A[0] + K;
		int mx = max(a, b), mn = min(a, b); 
		for (int i = 1; i < N - 1; i ++) {
			if (A[i] - mn < mx - A[i]) {
				mx = max(mx, A[i] + K);
			}
			else {
				mn = min(mn, A[i] - K);
			}
		}
		return min(A[N - 1] - A[0], mx - mn);
	}
}

int main() {
	freopen("in", "r", stdin);
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i ++) {
		scanf("%d", &A[i]);
	}
	printf("%d\n", smallestRangeII());
	return 0;
}
