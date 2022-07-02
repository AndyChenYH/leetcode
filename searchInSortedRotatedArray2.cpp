#include "../utils.cpp"
using namespace std;

// vector<int> ar = {0, 0, 0, 0, 1, 0, 0};
// vector<int> ar = {2, 2, 2, 2, 1, 2};
// vector<int> ar = {2, 1, 2, 2, 2, 2};
// vector<int> ar = {2,5,6,0,0,1,2};
vector<int> ar = {1, 2, 0, 1, 1, 1};
int tar = 0;
bool sol(int ll, int rr) {
	if (rr - ll == 1) {
		return tar == ar[ll];
	}
	int l = ll, r = rr - 1, ans = -1;
	while (l <= r) {
		int m = (r + l) / 2;
		if (ar[m] == tar) return true;
		db(l, r, m);
		if (ar[m] > ar[m + 1]) {
			ans = m;
			break;
		}
		if (ar[m] == ar[rr - 1]) {
			if (sol(m + 1, r + 1)) return true;
		}	
		if (ar[m] <= ar[rr - 1]) {
			r = m - 1;
		}
		else if (ar[m] > ar[rr - 1]) {
			l = m + 1;
		}
	}
	db(ans);
	if (ans == -1) ans = 0;
	l = ll, r = ans;
	while (l <= r) {
		int m = (r + l) / 2;
		if (ar[m] == tar) {
			return true;
		}
		if (ar[m] < tar) {
			l = m + 1;
		}
		else  r = m - 1;
	}
	l = ans + 1, r = rr - 1;
	while (l <= r) {
		int m = (r + l) / 2;
		if (ar[m] == tar) {
			return true;
		}
		if (ar[m] < tar) {
			l = m + 1;
		}
		else  r = m - 1;
	}
	return false;
}
int main() {
	printf("%d\n", sol(0, ar.size()));
}


