#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define psb push_back
#define tup tuple
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define E exit(0)
#define F function
#define V vector
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define pt(...) pt_out(__VA_ARGS__)
#define INF INT_MAX / 2
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define MN 1000

int NL, NK, lb, ub;
V<int> ca = {6, 5, 0, 0};
int main() {
	NL = ca.size();
	NK = 2;
	lb = 1;
	ub = 5;
	int win = 0;
	for (int i = 0; i < NK; i ++) {
		win += ca[i];
	}
	int pt = 0;
	if (win < lb) { pt --; }
	else if (ub < win) { pt ++; }
	for (int i = NK; i < NL; i ++) {
		db(win);
		win = win - ca[i - NK] + ca[i];
		if (win < lb) { pt --; }
		else if (ub < win) { pt ++; }
	}
	db(pt);
		
	return 0;
}
