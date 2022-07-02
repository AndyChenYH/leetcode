#include <iostream>
#include "../utils.cpp"
#include <string>
using namespace std;

int main() {
	string path = "/a/b/././..";
	string cur = "";
	vector<string> tok;
	for (int i = 1; i < path.size(); i ++) {
		if (path[i] == '/') {
			tok.push_back(cur);
			cur = "";
		}
		else cur.push_back(path[i]);
	}
	if (cur != "") tok.push_back(cur);
	list<string> st;
	for (string s : tok) {
		if (s == "." || s == "") continue;
		if (s == "..") {
			if (!st.empty()) st.pop_back();
		}
		else st.push_back(s);
	}
	string res = "";
	for (string s : st) {
		res += "/" + s;
	}
	if (res.empty()) res = "/";
	puts(res.c_str());

}
