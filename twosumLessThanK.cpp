#include <bits/stdc++.h>
using namespace std;

// two pointers
const int INF = 1e9 + 10;
int main() {
	vector<int> ar = {10,20,30};
	int k = 15;
	int N = ar.size();
	sort(ar.begin(), ar.end());
	int l = 0, r = N - 1;
	int mx = -INF;
	while (l < r) {
		if (ar[l] + ar[r] < k) {
		  	mx = max(mx, ar[l] + ar[r]);
			l ++;
		}
		else {
			r --;
		}
	}
	if (mx == -INF) mx = -1;
	printf("%d\n", mx);
}

/*
// binary search
const int INF = 1e9 + 10;
int main() {
	vector<int> ar = {-1, -1, 2};
	int k = 15;
	sort(ar.begin(), ar.end());
	int N = ar.size();
	int mx = -INF;
	for (int i = 0; i < N - 1; i ++) {
		int l = i + 1, r = N - 1, ans = -1;
		int t = k - ar[i];
		while (l <= r) {
			int m = (l + r) / 2;
			if (ar[m] < t) {
				ans = m;
				l = m + 1;
			}
			else r = m - 1;
		}
		if (ans != -1) {
			mx = max(mx, ar[i] + ar[ans]);
		}
	}
	if (mx == -INF) mx = -1;
	printf("%d\n", mx);
}
*/
