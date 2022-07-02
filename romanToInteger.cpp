#include <bits/stdc++.h>
using namespace std;

int main() {
	string s = "MCMXCIV";
	unordered_map<char, int> mp = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000},
	};
	int res = 0;
	for (int i = 0; i < (int) s.size(); i ++) {
		if (i != s.size() - 1 && mp[s[i]] < mp[s[i + 1]]) {
			res += mp[s[i + 1]] - mp[s[i]];
			i ++;
		}
		else res += mp[s[i]];
	}
	cout << res << endl;
}
