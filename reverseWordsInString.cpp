#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int N = s.size();
        vector<string> res;
        string tmp = "";
        for (int i = 0; i < N; i ++) {
            if (s[i] != ' ') {
                tmp.push_back(s[i]);
            }
            if (i == N - 1 || s[i] == ' ') {
                res.push_back(tmp);
                tmp = "";
            }
        }
        reverse(res.begin(), res.end());
        string ret;
        for (int i = 0; i < (int) res.size(); i ++) {
            ret += res[i] + " ";
        }
        ret.pop_back();
        return ret;
    }
};

int main() {
	Solution sol;
	string s = " hello there";
	printf("|%s|\n", sol.reverseWords(s).c_str());
	return 0;
}
