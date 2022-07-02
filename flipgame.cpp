#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define mkp make_pair
#define T tuple
#define mkt make_tuple
#define rep(act, x) for (int lolol = 0; lolol < x; lolol ++) { act; }
#define fir first
#define sec second
#define E exit(0)
#define F function
#define V vector
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dbl(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out_line(__VA_ARGS__)
#define INF INT_MAX
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

string SS = "+++++++++";
// "----+----";
int NS;
bool turn = 0;

bool sol() {
	db(SS);
	int fn = 0;
	for (int i = 0; i < NS - 1; i ++) {
		if (SS[i] == '+' && SS[i + 1] == '+') {
			fn ++;
			SS[i] = SS[i + 1] = '-';
			bool res = sol();
			SS[i] = SS[i + 1] = '+';
			if (!res) {
				return true;	
			}
		}
	}
	return fn == 1;

}

int main() {
    db("hello world");
	NS = SS.size();
	cerr << sol() << endl;
	return 0;
}
