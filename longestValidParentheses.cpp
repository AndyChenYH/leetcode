#include <stdio.h>
#include <string>
using namespace std;

const int INF = 1e9 + 10;
class Solution {
	public:
		int longestValidParentheses(string s) {
			int mx = -INF;
			int N = s.size();
			for (int i = 0; i < N; i ++) {
				int b = 0;
				for (int j = i; 0 <= j; j --) {
					if (s[j] == '(') b ++;
					else b --;
					if (b == 0) {
						mx = max(mx, i - j + 1);
					}
				}
			}
			return mx;
		}
};

int main() {
	Solution sol;
	string s = ")()())";
	printf("%d\n", sol.longestValidParentheses(s));
	return 0;
}
