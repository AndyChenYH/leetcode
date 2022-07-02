#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
	vector<string> rows(numRows + 1, "");
	int curRow = 1;
	int inc = 1;
	for (char c : s) {
		rows[curRow].push_back(c);
		curRow += inc;
		if (curRow == numRows) inc = -1;
		if (curRow == 1) inc = 1;
	}
	string res = "";
	for (string r : rows) {
		res += r;
	}
	return res;
}
int main() {
	string s = "PAYPALISHIRING";
	int numRows = 4;
	cout << convert(s, numRows) << endl;
}
/*
a       a
a     a a
a   a   a
a a     a
a       a
*/
