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
#define mset multiset
#define mmap multimap
#define pii pair<int, int>
#define tiii trip<int, int, int>
#define ll long long
#define S string
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define MOD 1000000007
#define INF (2147483647 / 2)
#define printf(args...) fprintf(stderr, ##args)
using namespace std;


bool sol1(V<int> arr) {
	for (int i = 0; i < (int) arr.size(); i ++) {
		for (int j = 0; j < (int) arr.size(); j ++) {
			if (i == j) { continue; }
			if (arr[j] * 2 == arr[i]) {
				return true;
			}
		}
	}
	return false;
}

int sol2(S sa, S sb) {
	sort(sa.begin(), sa.end());
	sort(sb.begin(), sb.end());
	int ct = 0;
	int LS = sa.size();	
	int ai = 0, bi = 0;
	while (bi < LS) {
		while (ai < bi && sa[ai] < sb[bi]) { 
			ai ++; 
		}
		if (sa[ai] != sb[bi]) {
			ct ++;
		}
		bi ++;
	}
	return ct;
}
int sol4() {
	const V<pii> cse = {
		{-1, 1},   {1, 1},
		{-1, 0},   {1, 0},
	};
	const V<pii> pee = {
		{-1, 0},   {1, 0},
		{-1, -1},  {1, -1},
	};
	
}

int main() {
	return 0;
}
