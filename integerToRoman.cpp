#include <bits/stdc++.h>
using namespace std;

int main() {
	int num = 4;
	unordered_map<int, char> mp[] = {
		{
			{1, 'I'},
			{5, 'V'},
		},
		{
			{1, 'X'},
			{5, 'L'},
		},
		{
			{1, 'C'},
			{5, 'D'},
		},
		{
			{1, 'M'},
		}
	};
	vector<int> dig;
	for ( ; 0 < num; num /= 10) {
		dig.push_back(num % 10);
	}
	for (int d : dig) {
		printf("%d ", d);
	}
	puts("**********");
	string res = "";
	for (int i = 0; i < (int) dig.size(); i ++) {
		if (dig[i] <= 3) {
			for (int c = 0; c < dig[i]; c ++) {
				res += mp[i][1];
			}
		}
		else if (dig[i] == 4) {
			res += string({mp[i][5], mp[i][1]});
		}
		else if (5 <= dig[i] && dig[i] <= 8) {
			for (int c = 0; c < dig[i] - 5; c ++) {
				res += mp[i][1];
			}
			res += mp[i][5];
		}
		else {
			res += string({mp[i + 1][1], mp[i][1]});
		}
	}
	reverse(res.begin(), res.end());
	cout << res << endl;
}


/*
// hardcoded solution
class Solution {
public:
    string intToRoman(int num) {

	unordered_map<int, string> mp = {
		{3000, "MMM"},
		{2000, "MM"},
		{1000, "M"},
		{900, "CM"},
		{800, "DCCC"},
		{700, "DCC"},
		{600, "DC"},
		{500, "D"},
		{400, "CD"},
		{300, "CCC"},
		{200, "CC"},
		{100, "C"},
		{90, "XC"},
		{80, "LXXX"},
		{70, "LXX"},
		{60, "LX"},
		{50, "L"},
		{40, "XL"},
		{30, "XXX"},
		{20, "XX"},
		{10, "X"},
		{9, "IX"},
		{8, "VIII"},
		{7, "VII"},
		{6, "VI"},
		{5, "V"},
		{4, "IV"},
		{3, "III"},
		{2, "II"},
		{1, "I"},
	};
	string res = "";
	while (0 < num) {
		int po = pow(10, floor(log10(num)));
		int r = num % po;
		int l = num - r;
		res += mp[l];
		num = r;
	}
    return res;

    }
};
*/
