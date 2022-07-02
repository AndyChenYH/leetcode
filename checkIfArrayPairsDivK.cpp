#include <stdio.h>
#include <iterator>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
	public:
		bool canArrange(vector<int>& arr, int k) {
			int N = arr.size();
			for (int& d : arr) { 
				d %= k;
				if (d < 0) { d += k; }
			}
			unordered_multiset<int> st(arr.begin(), arr.end());
			for (int c = 0; c < N / 2; c ++) {
				auto a = *st.begin(); st.erase(st.begin());
				unordered_multiset<int>::iterator it;
				if (a == 0) {
					it = st.find(0);
				}
				else {
					it = st.find(k - a);
				}
				if (it == st.end()) return false;
				st.erase(it);
			}
			return true;
		}
};

int main() {
	vector<int> arr = {-1,1,-2,2,-3,3,-4,4};
	Solution s;
	printf("%d\n", s.canArrange(arr, 3));
	return 0;
}
