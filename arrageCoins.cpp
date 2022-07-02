#include <stdio.h>

const int INF = 1e9 + 10;
class Solution {
public:
    int arrangeCoins(int n) {
        int l = 0, r = INF, ans = -1;
        while (l <= r) {
			long long m = (long long) l + (r - l) / 2;
			if ((m *m + m) / 2 <= n) {
				ans = m;
				l = m + 1;
			}
			else { r = m - 1; }
        }
        return ans;
        
    }
};

int main() {
	Solution s;
	printf("%d\n", s.arrangeCoins(8));
	return 0;
}