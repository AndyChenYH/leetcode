#include "../utils.cpp"
using namespace std;

int sol() {
	vector<int> ar = {2,5,6,0,0,1,2};
	int tar = 3;
	if (ar.size() == 1) {
	  	return tar == ar[0] ? 0 : -1;
	}
	int N = ar.size();
	int l = 0, r = N - 1, ans = -1;
	while (l <= r) {
		int m = (r + l) / 2;
//		assert(m < N - 1);
		if (ar[m] > ar[m + 1]) {
			ans = m;
			break;
		}
		if (ar[m] < ar[N - 1]) {
			r = m - 1;
		}
		else if (ar[m] > ar[N - 1]) {
			l = m + 1;
		}
	}
	if (ans == -1) ans = 0;
	l = 0, r = ans;
	while (l <= r) {
		int m = (r + l) / 2;
		if (ar[m] == tar) {
			return m;
			break;
		}
		if (ar[m] < tar) {
			l = m + 1;
		}
		else  r = m - 1;
	}
	l = ans + 1, r = N - 1;
	while (l <= r) {
		int m = (r + l) / 2;
		if (ar[m] == tar) {
			return m;
		}
		if (ar[m] < tar) {
			l = m + 1;
		}
		else  r = m - 1;
	}
	return -1;
}
int main() {
	printf("%d\n", sol());
}

