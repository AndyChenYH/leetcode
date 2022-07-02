#include <stdio.h>
#include <algorithm>
using namespace std;

// greedy

int main() {
	int ar[] = {3, 2, 1, 0, 4};
	int N = sizeof(ar) / sizeof(int);
	int last = N - 1;
	for (int i = N - 1; 0 <= i; i --) {
		int l = i + 1, r = i + ar[i];
		if (l <= last && last <= r) {
			last = i;
		}
	}
	printf("%d\n", last);
}

/*
// DP bottom up
const int MN = 3e4;
int main() {
	int ar[] = {4, 2, 0, 0, 1, 1, 1, 0};
	int N = sizeof(ar) / sizeof(int);
	bool dp[MN] = {};
	for (int i = N - 1; 0 <= i; i --) {
		if (i == N - 1) {
			dp[i] = true;
			continue;
		}
		dp[i] = false;
		for (int j = i + 1; j <= i + ar[i]; j ++) {
			dp[i] |= dp[j];
		}
	}
	for (int i = 0; i < N; i ++) {
		printf("%d ", dp[i]);
	}
	puts("");
}
*/

/*
// backtracking solution
int main() {
	int ar[] = {2, 3, 1, 1, 4};
	int N = sizeof(ar) / sizeof(int);
	function<bool(int)> can = [&] (int i) {
		if (i == N - 1) return true;
		for (int j = i + 1; j <= i + ar[i]; j ++) {
			if (can(j)) return true;
		}
		return false;
	};
	printf("%d\n", can(0));
}
*/


/*
// DP + prefix sum solution
const int MN = 3e4;
int main() {
	int ar[] = {3, 2, 2, 0, 2, 0, 5, 0};
	int N = sizeof(ar) / sizeof(int);
	bool dp[MN] = {};
	int psum[MN] = {};
	auto query = [&] (int a, int b) -> int {
		if (b == N - 1) return psum[a];
		return psum[a] - psum[b + 1];
	};
	psum[N - 1] = 1;
	dp[N - 1] = true;
	for (int i = N - 2; 0 <= i; i --) {
		dp[i] = query(i + 1, min(N - 1, i + ar[i]));
		psum[i] = dp[i] + psum[i + 1];
	}
	for (int i = 0; i < N; i ++) {
		printf("%d ", dp[i]);
	}
	puts("");
	
}
// dp[i] = any dp[j], for i < j < i + ar[i]
*/


