#include "../utils.cpp"
using namespace std;

int main() {
	string s = " -2147483649 hello world";
	auto sol = [&] () {
		s.erase(remove_if(s.begin(), s.end(), [] (char c) {
					return c == ' ' || 'a' <= tolower(c) && tolower(c) <= 'z'; }), s.end());
		if (count_if(s.begin(), s.end(), [] (char c) { return '0' <= c && c <= '9'; }) == 0) return 0;
		if (s.empty()) return 0;
		int sign = s[0] == '-' ? -1 : 1;
		if (s[0] == '+' || s[0] == '-') s.erase(s.begin());
		int i = 0;
		for (; i < s.size() && s[i] == '0'; i ++);
		if (i == s.size()) return 0;
		s = string(s.begin() + i, s.end());
		string mn = "2147483648", mx = "2147483647";
		auto bigger = [&] (string a, string b) {
			if (a.size() > b.size()) return true;
			if (b.size() > a.size()) return false;
			assert(a.size() == b.size());
			for (int i = 0; i < a.size(); i ++) {
				if (a[i] > b[i]) return true;
			}
			return false;
		};
		if (sign == -1 && bigger(s, mn)) s = mn;
		if (sign == 1 && bigger(s, mx)) s = mx;
		assert(!s.empty() && '0' <= s[0] && s[0] <= '9');
		int res = s[0] - '0';
		for (int ii = 1; ii < s.size(); ii ++) {
			res = res * 10 + s[ii] - '0';
		}
		return res * sign;
	};
	int r = sol();
	printf("%d\n", r);
}
