#include <bits/stdc++.h>
using namespace std;

int main() {
	string s = "()";
	list<char> st;
	unordered_map<char, char> mat = {
		{'{', '}'},
		{'[', ']'},
		{'(', ')'},
	};
	for (char c : s) {
		if (c == '{' || c == '[' || c == '(') {
			st.push_back(c);
		}
		else {
			if (st.empty() || mat[st.back()] != c) {
				puts("false");
				break;
			}
			st.pop_back();
		}
	}

	if (st.empty()) puts("true");
	else puts("false");

}
