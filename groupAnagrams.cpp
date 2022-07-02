#include <iostream>
#include "../utils.cpp"
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	vector<string> s {"a"};
	unordered_map<string, vector<string>> mp;
	for (string ss : s) {
		string a = ss;
		sort(a.begin(), a.end());
		if (mp.find(a) == mp.end()) {
			mp.insert({a, {ss}});
		}
		else mp[a].push_back(ss);
	}
	vector<vector<string>> res;
	for (auto p : mp) {
		res.push_back(p.second);
	}
	db(res);
}
