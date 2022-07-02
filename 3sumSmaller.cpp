#include <bits/stdc++.h>
using namespace std;

// two pointer
//  0  1  2  3  4
// {1, 3, 4, 5, 8}
int main() {
	vector<int> ar = {1, 2, 3, 4, 5};
	int tar = 100;
	sort(ar.begin(), ar.end());
	int N = ar.size();
	int ct = 0;
	for (int i = 0; i < N - 2; i ++) {
		int l = i + 1, r = N - 1;
		while (l < r) {
			if (ar[i] + ar[l] + ar[r] < tar) {
				ct += r - l;
				l ++;
			}
			else r --;
		}
	}
	printf("%d\n", ct);
}
/*
// binary search
int main() {
	vector<int> ar = {1, 2, 3, 4, 5};
	int tar = 100;
	sort(ar.begin(), ar.end());
	int N = ar.size();
	int ct = 0;
	for (int i = 0; i < N - 2; i ++) {
		for (int j = i + 1; j < N - 1; j ++) {
			int l = j + 1, r = N - 1, ans = -1;
			int t = tar - ar[i] - ar[j];
			while (l <= r) {
				int m = (l + r) / 2;
				if (ar[m] < t) {
					ans = m;
					l = m + 1;
				}
				else r = m - 1;
			}
			if (ans != -1) {
				printf("%d %d %d\n", ar[i], ar[j], ar[ans]);
				ct += ans - j;
			}
		}
	}
	printf("%d\n", ct);
}
*/
