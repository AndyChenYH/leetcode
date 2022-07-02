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

const int MT = 26;
int LN;
V<char> r_tsk;
V<int> tsk;
int main() {
	r_tsk = {'A'};
	LN = 2;
	
	LN ++;
	tsk = V<int>(MT); for (char c : r_tsk) {
		tsk[c - 'A'] ++;
	}
	db(tsk);
	queue<pii> que;
	V<int> inq(MT);
	int tt = 0;
	while (true) {
		db(que);
		while (!que.empty() && LN <= tt - que.front().se) {
			inq[que.front().fi] --;
			assert(0 <= inq[que.front().fi]);
			que.pop();
		}
		bool ht = false;

		for (int c = 0; c < MT; c ++) {
			if (tsk[c] != 0) {
				ht = true;
			}
		}
		for (int c = 0; c < MT; c ++) {
			if (tsk[c] != 0 && inq[c] == 0) {
				que.push({c, tt});
				tsk[c] --;
				inq[c] ++;
				break;
			}
		}
		tt ++;
		if (!ht) { break; }
	}
	db(tt);
	return 0;
}
