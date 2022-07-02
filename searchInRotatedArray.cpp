#include "../utils.cpp"
using namespace std;

const int INF = 1e9;
int main() {
	vector<int> ar = {4,5,6,7,0,1,2};
	int tar = 2;
	int N = ar.size() + 2;
	auto get = [&] (int i) {
		if (i == 0) return -INF;
		if (i == ar.size()) return INF;
		return ar[i - 1];
	};
	int l = 0, r = N - 1;
	int ans = -1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (m == 0 || get(m) < get(m - 1)) {
			ans = m;
			break;
		}
		if (get(0) < get(m)) {
			l = m + 1;
		}
		else r = m - 1;
	}
	if (ans == -1) ans = 0;
	l = 0, r = ans;
	int ret = -1;
	for (int ii = 0; ii < 2; ii ++) {
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (get(m) == tar) {
				ret = m;
				goto L1;
			}
			else if (get(m) < tar) {
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		l = ans, r = N - 1;
	}
L1:;
	printf("%d\n", ret - 1);
}
