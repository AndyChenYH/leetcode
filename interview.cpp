#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int minAreaRect(vector<vector<int>>& points) {
			vector<pair<int, int>> pts;
			for (vector<int> pt : points) pts.push_back({pt[0], pt[1]});
			sort(pts.begin(), pts.end());

			set<pair<int, int>> sl, sr;

		}
};
