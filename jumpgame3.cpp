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
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ll long long
#define S string
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define MOD int(1e9 + 7)
#define INF (INT_MAX / 2)
using namespace std;

int LN;
int ss;
V<int> arr;
int main() {
	arr = {3,0,2,1,2};
	ss = 2;
	LN = arr.size();
	auto can = [&] (int i) -> bool {
		return 0 <= i && i < LN;
	};
	bool yes = false;
	// visited indices
	V<bool> vis(LN, false);
	queue<int> que = {};
	que.push(ss);
	while (!que.empty()) {
		int fr = que.front();
		que.pop();
		int n1 = fr - arr[fr];
		if (can(n1) && !vis[n1]) {
			if (arr[n1] == 0) {
				yes = true;
				break;
			}
			vis[n1] = true;
			que.push(n1);
		}
		int n2 = fr + arr[fr];
		if (can(n2) && !vis[n2]) {
			if (arr[n2] == 0) {
				yes = true;
				break;
			}
			vis[n2] = true;
			que.push(n2);
		}
	}
	db(yes);
	return 0;
}
