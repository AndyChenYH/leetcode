#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
	public:
		vector<int> prisonAfterNDays(vector<int>& cells, int N) {
			map<vector<int>, int> occ;
			int ct = 0;
			vector<vector<int>> se;
			vector<int> c = cells;
			do {
				occ.insert({c, ct});
				se.push_back(c);
				vector<int> t = c;
				t[0] = t[7] = 0;
				for (int i = 1; i < 7; i ++) {
					t[i] = c[i - 1] == c[i + 1];
				}
				c = t;
				ct ++;
			}while (occ.find(c) == occ.end());

			int rep = occ.at(c);
			int sz = se.size() - rep;
			if (N < rep) {
				return se[N];
			}
			return se[rep + (N - rep) % sz];
		}
};
int main() {
	vector<int> cells = {1,0,0,1,0,0,1,0};
	Solution s;
	vector<int> res = s.prisonAfterNDays(cells, 1000000000);
	for (int d : res) {
		printf("%d ", d);
	}
	puts("");
	return 0;
}
