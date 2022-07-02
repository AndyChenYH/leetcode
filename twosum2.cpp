#include <bits/stdc++.h>
using namespace std;

// binary search
int main() {
	vector<int> ar = {-1,0};
	int t = -1;
	int N = ar.size();
	for (int i = 0; i < N; i ++) {
		int tar = t - ar[i];
		int l = i + 1, r = N - 1;
		int ans = -1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (tar <= ar[m]) {
				ans = m;
				r = m - 1;
			}
			else l = m + 1;
		}
		if (ans != -1 && ar[ans] == tar) {
			printf("%d %d\n", i, ans);
			break;
		}
	}
}
/*
// two pointers
int main() {
	vector<int> ar = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int t = 6;
	int N = ar.size();
	int l = 0, r = N - 1;
	while (true) {
		assert(l <= r);
		if (ar[l] + ar[r] == t) {
			printf("%d %d\n", l, r);
			break;
		}
		else if (ar[l] + ar[r] < t) l ++;
		else r --;
	}
}
*/
