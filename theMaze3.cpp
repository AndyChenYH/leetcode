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

int LR, LC;
const V<T<
pii ss, dd;
V<V<pair<int, S>>> mnd;
V<V<int>> mb;
int main() {
	mb = {
		{0, 0, 0, 0, 0},
		{1, 1, 0, 0, 1},
		{0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1},
		{0, 1, 0, 0, 0},
	};
	ss = {4, 3};
	dd = {0, 1};
	LR = mb.size();
	LC = mb[0].size();
	queue<T<int, int, int, S>> que;
	que.push({ss.fi, ss.se, 0, ""});
	while (!que.empty()) {
		T<int, int, int, S> fr = que.front();
		que.pop();

	}
	return 0;
}
