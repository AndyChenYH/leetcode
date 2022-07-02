#include <bits/stdc++.h>
#define INF (INT_MAX / 2)
#define V vector
#define pii pair<int, int>
using namespace std;

int LN;
V<int> arr;
int main() {
	arr = {1, 8, 6, 2, 5, 3, 8, 3, 7};
	LN = arr.size();
	int li = 0, ri = LN - 1;
	int mx = -INF;
	while (li < ri) {
		mx = max(mx, min(arr[li], arr[ri]) * (ri - li));
		if (arr[li] < arr[ri]) {
			li ++;
		}
		else {
			ri --;
		}
	}
	cerr << mx << endl;
	return 0;
}
