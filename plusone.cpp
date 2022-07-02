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
#define INF INT_MAX
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

V<int> num = {9899};
V<int> sol() {
	num.insert(num.begin(), 0);
	num[num.size() - 1] ++;
	for (int i = num.size() - 1; 10 == num[i]; i --) {
		num[i] = 0;
		num[i - 1] ++;
	}	
	if (num[0] == 0) {
		num.erase(num.begin());
	}
	return num;
}

int main() {
	db(sol());
	return 0;
}
