#include <bits/stdc++.h>
using namespace std;

int main() {
	//						0 1 2 3 4 5
	vector<int> ar = {5,7,8,8,8,10};
	int t = 8;
	int N = ar.size();
	vector<int> res(2);
	for (int ct = 0; ct < 2; ct ++) {
		int l = 0, r = N - 1, ans = -1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (ct == 0) {
				if (ar[m] <= t) {
					ans = m;
					l = m + 1;
				}
				else r = m - 1;
			}
			else {
				if (t <= ar[m]) {
					ans = m;
					r = m - 1;
				}
				else l = m + 1;
			}
		}
		if (ans != -1 && ar[ans] != t) ans = -1;
		res[ct] = ans;
	}
	swap(res[0], res[1]);
	printf("%d %d\n", res[0], res[1]);
}
