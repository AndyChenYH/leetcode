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

int NS = 1234;

int main() {
	V<int> memo(NS + 1, -1);
	F<bool(int)> sol = [&] (int ns) -> bool {
		if (memo[ns] != -1) {
			return memo[ns];
		}
		if (ns - 3 <= 0) { 
			memo[ns] = true;
			return true; 
		}
		bool res = !(sol(ns - 1) && sol(ns - 2) && sol(ns - 3));
		memo[ns] = res;
		return res;
	};
	db(sol(NS));


	return 0;
}
