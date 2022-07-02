#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
	public:
		long long minEatingSpeed(vector<long long>& piles, long long H) {
			auto yes = [&] (long long k) {
				long long t = 0;
				for (long long p : piles) {
					t += p / k + (p % k != 0);
				}
				return t <= H;
			};
			long long l = 0, r = 1, ans = -1;
			while (!yes(r)) r *= 2;
			while (l <= r) {
				long long m = l + (r - l) / 2;
				if (yes(m)) {
					ans = m;
					r = m - 1;
				}
				else l = m + 1;
			}
			return ans;
		}
};

long long main() {
	Solution sol;
	vector<long long> piles = {3, 6, 7, 11};
	long long H = 8;
	prlong longf("%d\n", sol.minEatingSpeed(piles, H));
	return 0;
}
