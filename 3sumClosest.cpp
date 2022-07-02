#include <bits/stdc++.h>
using namespace std;

// two pointer
const int INF = 1e9 + 10;
int main() {
	vector<int> ar = {1, 2, 3, 50};
	int tar = 10;
	int N = ar.size();
	int clo = INF;
	sort(ar.begin(), ar.end());
	for (int i = 0; i < N - 1; i ++) {
		int l = i + 1, r = N - 1;
		while (l < r) {
			int sm = ar[i] + ar[l] + ar[r];
			if (abs(tar - sm) < abs(tar - clo)) {
				clo = sm;
			}
			if (sm < tar) {
				l ++;
			}
			else r --;
		}
	}
	printf("%d\n", clo);
}

/*
// binary search
const int INF = 1e9 + 10;
int main() {
	vector<int> ar = {1, 2, 3, 50};
	sort(ar.begin(), ar.end());
	int t = 10;
	int N = ar.size();
	int mndif = INF, clo;
	for (int i = 0; i < N - 2; i ++) {
		for (int j = i + 1; j < N - 1; j ++) {
			for (int ct = 0; ct < 2; ct ++) {
				int l = j + 1, r = N - 1, ans = j + 1;
				int tar = t - ar[i] - ar[j];
				while (l <= r) {
					int m = (l + r) / 2;
					if (ct == 0) {
						if (tar <= ar[m]) {
							ans = m;
							r = m - 1;
						}
						else l = m + 1;
					}
					else {
						if (ar[m] <= tar) {
							ans = m;
							l = m + 1;
						}
						else r = m - 1;
					}
				}
				int dif = abs(tar - ar[ans]);
				if (dif < mndif) {
					mndif = dif;
					clo = ar[i] + ar[j] + ar[ans];
				}
			}
		}
	}
	printf("%d\n", clo);
}
*/
