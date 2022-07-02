#include <bits/stdc++.h>
using namespace std;

int reverse(long x) {
	bool neg = x < 0;
	x = abs(x);
	vector<int> ar = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
	vector<int> res;
	for (int i = 0; 0 < x; i ++, x /= 10) {
		int d = x % 10;
		res.push_back(d);
	}
	if (res.size() == ar.size()) {
		int ia = ar.size() - res.size();
		for (int i = 0; i < (int) res.size(); i ++, ia ++) {
			if (res[i] < ar[ia]) break;
			if (ar[ia] < res[i]) {
				return 0;
			}
		}
	}
	int ret = 0;
	for (int d : res) {
		ret = ret * 10 + d;
	}
	if (neg) ret *= -1;
	return ret;
}
int main() {
	printf("%d\n", reverse(7563847412));
}
