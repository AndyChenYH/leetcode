#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	int mx = 0;
	for (string s : strs) {
		mx = max(mx, (int) s.size());
	}
	string res = "";
	for (int i = 0; i < mx; i ++) {
		for (int j = 0; j < (int) strs.size(); j ++) {
			if (strs[j][i] != strs[0][i]) {
				goto L1;
			}
		}
		res += strs[0][i];
	}
L1:;
	return res;
}
int main() {
	vector<string> strs = {"flower", "flow", "flight"};
	cout << longestCommonPrefix(strs) << endl;
}
