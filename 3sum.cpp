#include <bits/stdc++.h>
using namespace std;



/*
// hashtable method

namespace std {
	template <>
		struct hash<vector<int>> {
			size_t operator()(const vector<int>& vec) const {
				size_t seed = vec.size();
				for(auto& i : vec) {
					seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
				}
				return seed;
			}
		};
}
int main() {
	vector<int> nums = {-1,0,1,2,-1,-4};
	int N = nums.size();
	unordered_set<int> saw;
	saw.insert(nums[0]);
	vector<vector<int>> res;
	for (int i = 1; i < N; i ++) {
		for (int j = i + 1; j < N; j ++) {
			int t = 0 - nums[i] - nums[j];
			if (saw.find(t) != saw.end()) {
				res.push_back({nums[i], nums[j], t});
			}
		}
		saw.insert(nums[i]);
	}
	unordered_set<vector<int>> st;
	for (vector<int> v : res) {
		sort(v.begin(), v.end());
		st.insert(v);
	}
	vector<vector<int>> ret = {};
	for (vector<int> v : st) ret.push_back(v);
	for (vector<int> v : ret) {
		for (int d : v) printf("%d ", d);
		puts("");
	}

}
*/
