#include "../utils.cpp"
#include "unordered_map"
using namespace std;

string s1 = "c";
string s2 = "a";
string s3 = "ac";

bool sol() {
	vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1));
	for (int a = 0; a < s1.size(); a ++) {
		for (int b = 0; b < s2.size(); b ++) {
			int c = a + b + 1;
			if (c < 0) dp[a + 1][b + 1] = true;
			else {
				assert(0 <= a || 0 <= b);
				bool yes = false;
				if (0 <= a && s1[a] == s3[c]) {
					yes |= dp[a - 1 + 1][b + 1];
				}
				if (0 <= b && s2[b] == s3[c]) {
					yes |= dp[a + 1][b - 1 + 1];
				}
				dp[a + 1][b + 1] = yes;
			}
		}
	}
	return dp[s1.size()][s2.size()];
}
int main() {
	bool res = sol();
	printf("%d\n", res);
}
