#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> ar = {3,5,3,2,0};
	int N = ar.size();
	int l = 0, r = N - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (ar[m - 1] < ar[m] && ar[m + 1] < ar[m]) {
			printf("%d\n", m);
			break;
		}
		else if (ar[m - 1] < ar[m] && ar[m] < ar[m + 1]) {
			l = m + 1;
		}
		else r = m - 1;
	}
}
