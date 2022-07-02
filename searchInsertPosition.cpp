#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> nums = {-1, 0, 1, 100};
	int target = 0;
	int l = 3, r = 3;
	int ans = 3;
	while (l <= r) {
		int m = (l + r) / 2;
		if (target <= nums[m]) {
			ans = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	printf("%d\n", ans);
}
