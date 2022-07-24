#include "../utils.cpp"
using namespace std;

string s = "101023";
vector<string> ip;
bool valid(string ss) {
	return !ss.empty() && ss.size() < 4 && (ss[0] != '0' || ss.size() == 1) && stoi(ss) <= 255;
}
void recur(int i, string wd) {
	if (!wd.empty() && stoi(wd) > 255) return;
	if (i == s.size() || ip.size() == 4) {
		if (i < s.size() || ip.size() < 4);
		else {
			string rr = ip[0];
			for (int i = 1; i < ip.size(); i ++) {
				rr += "." + ip[i];
			}
			db(rr);
		}
		return;
	}
	string nw = wd + string(1, s[i]);
	if (valid(nw)) {
		ip.push_back(nw);
		recur(i + 1, "");
		ip.pop_back();
	}
	recur(i + 1, nw);
}

int main() {
	recur(0, "");
}
