#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
		sort(A.begin(), A.end());
		if (A.back() - A.front() <= 2 * K) {
			return 0;
		}
		else {
			return A.back() - K - (A.front() + K);
		}
    }
};

int main() {
	Solution sol;
	vector<int> A = {1, 3, 6};
	int K = 3;
	printf("%d\n", sol.smallestRangeI(A, K));
	return 0;
}
