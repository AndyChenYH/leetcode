#include "../utils.cpp"
using namespace std;

int main() {
	vector<vector<int>> mt = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
	int t = 70;
	int l = 0, r = mt.size() - 1;
	int ans = -1;
	while (l <= r) {
		int m = (r + l) / 2;
		if (mt[m][0] <= t) {
			l = m + 1;
			ans = m;
		}
		else {
			r = m - 1;
		}
	}
	bool yes = false;
	if (ans == -1) goto L1;
	l = 0, r = mt[0].size() - 1;
	while (l <= r) {
		db(l, r);
		int m = (r + l) / 2;
		if (mt[ans][m] == t) {
			yes = true;
			break;
		}
		if (mt[ans][m] < t) {
			l = m + 1;
		}
		else r = m - 1;
	}
L1:;
	printf("%d\n", yes);
}
