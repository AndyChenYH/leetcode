/*
435. Non-overlapping Intervals 
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
*/
#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define psb push_back
#define mkp make_pair
#define mkt make_trip
#define fi first
#define se second
#define th third
#define E exit(0)
#define F function
#define V vector
#define pii pair<int, int>
#define tiii trip<int, int, int>
#define ll long long
#define S string
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define MOD 1000000007
#define INF (2147483647 / 2)
#define TLE throw logic_error("oops")
using namespace std;


int LN;
V<pii> its;
V<V<int>> lG;
int main() {
	its = {{0,2},{1,3},{1,3},{2,4},{3,5},{3,5},{4,6}};
	LN = its.size();
	sort(its.begin(), its.end());
	lG = V<V<int>>(LN, V<int>(0));
	db(its);
	for (int i = 0; i < LN; i ++) {
		int ei = i + 1;
		while (ei < LN && its[ei].fi < its[i].se) {
			lG[i].psb(ei);
			lG[ei].psb(i);
			ei ++;
		}
	}	
	db(plG(lG));
	auto cmp = [&] (V<int> a, V<int> b) -> bool { 
		return a.size() < b.size(); 
	};
	int ct = 0;
	int u = max_element(lG.begin(), lG.end(), cmp) - lG.begin();
	while (lG[u].size() != 0) {
		db(u, plG(lG));
		while (lG[u].size() != 0) {
			int v = lG[u][0];
			lG[v].erase(find(lG[v].begin(), lG[v].end(), u));
			lG[u].erase(lG[u].begin());
		}
		ct ++;
		u = max_element(lG.begin(), lG.end(), cmp) - lG.begin();
	}
	db(ct, plG(lG));
	return 0;
}
