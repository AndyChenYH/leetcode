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
#define ll long long
#define S string
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define MOD 1000000007
#define INF (2147483647 / 2)
#define printf(args...) fprintf(stderr, ##args)
using namespace std;

int LA;
int K;
V<int> arr;
int main() {
	K = 4;
	arr = {-7,-8,7,5,7,1,6,0};
	LA = arr.size();
	auto cmp = [&] (int a, int b) -> bool { return a > b; };
	mset<int, decltype(cmp)> win(cmp);
	for (int i = 0; i < K; i ++) {
		win.insert(arr[i]);
	}	
	V<int> res = {};
	res.psb(*win.begin());
	for (int i = K; i < LA; i ++) {
		win.insert(arr[i]);
		win.erase(win.find(arr[i - K]));
		res.psb(*win.begin());
	}
	db(res);
	return 0;
}
