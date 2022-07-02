#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define psb push_back
#define mkp make_pair
#define mkt make_tuple
#define fi first
#define se second
#define T tuple
#define F function
#define S string
#define V vector
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ll long long
#define E exit(0)
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define MOD int(1e9 + 7)
#define INF (INT_MAX / 2)
using namespace std;

int LN, LK;
V<int> nums;
S r_nums;
int main() {
	r_nums = "1234567890";
	LK = 9;
	nums = {};
	for (char c : r_nums) {
		nums.psb(c - '0');
	}
	list<int> st = {};
	for (int d : nums) {
		while (!st.empty() && 0 < LK && d < *prev(st.end(), 1)) {
			st.pop_back();
			LK --;
		}
		st.psb(d);
	}
	for (int c = 0; c < LK; c ++) {
		st.pop_back();
	}
	while (!st.empty() && *st.begin() == 0) {
		st.pop_front();
	}
	if (st.empty()) {
		st.psb(0);
	}
	S res = "";
	for (int d : st) {
		res.psb(d + '0');
	}
	db(st, res);
	return 0;
}
