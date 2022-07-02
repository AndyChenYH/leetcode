#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> mp = { "", "",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz"
	};
	string dig = "2";
	vector<string> res;
	string cur;
	function<void(int)> recur = [&] (int i) {
		if (i == (int) dig.size()) {
			res.push_back(cur);
			return;
		}
		for (char c : mp[dig[i] - '0']) {
			cur.push_back(c);
			recur(i + 1);
			cur.pop_back();
		}
	};
	recur(0);
	for (string s : res) cout << s << endl;
}
