#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> nums = {11, 7, 2, 15};
	int target = 9;
	vector<int> tmp;
	for (int i = 0; i < (int) nums.size(); i ++) {
		tmp.push_back(i);
	}
	sort(tmp.begin(), tmp.end(), [&] (int a, int b) { return nums[a] < nums[b]; });
	sort(nums.begin(), nums.end());
	for (int i = 0; i < (int) nums.size(); i ++) {
		int t = target - nums[i];
		int l = i + 1, r = nums.size() - 1;
		int ans = -1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (t <= nums[m]) {
				ans = m;
				r = m - 1;
			}
			else l = m + 1;
		}
		if (ans != -1 && nums[ans] == t) {
			printf("%d %d\n", tmp[i], tmp[ans]);
		}
	}
}
