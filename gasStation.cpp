#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define psb push_back
#define mkp make_pair
#define mkt make_tuple
#define fi first
#define se second
#define T tuple
#define E exit(0)
#define F function
#define V vector
#define S string
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ll long long
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define MOD int(1e9 + 7)
#define INF (INT_MAX / 2)
using namespace std;

int LG;
V<int> gas, cost;
int main() {
	/*
	gas = {1, 2, 3, 4, 5};
	cost = {3, 4, 5, 1, 2};
	*/

	gas = {0, 0, 0};
	cost = {1, 1, 1};
	LG = gas.size();
	int st = 0;
	int cur = 0;
	for (int ii = 0; ii < LG * 2; ii ++) {
		int i = ii % LG;
		cur = cur + gas[i] - cost[i];
		if (cur < 0) {
			st = i + 1;
			cur = 0;
		}
		if (ii - st == LG - 1) { 
			db(ii, i, st, cur);
			break; 
		}
	}
	if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
		st = -1;
	}
	db(st);
	return 0;
}
