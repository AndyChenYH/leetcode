#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;
int main() {
	vector<int> ar = {2,7,11,100};
	int t = 20;
	int N = ar.size();
	int mndif = INF;
	int clo;
	for (int i = 0; i < N - 1; i ++) {
		int tar = t - ar[i];
		for (int ct = 0; ct < 2; ct ++) {
			int l = i + 1, r = N - 1;
			int ans = i + 1;
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
					if (ar[m] <= t) {
						ans = m;
						l = m + 1;
					}
					else r = m - 1;
				}
			}
			int dif = abs(tar - ar[ans]);
			if (dif < mndif) {
				mndif = dif;
				clo = ar[i] + ar[ans];
			}

		}
	}
	printf("%d\n", clo);
}
