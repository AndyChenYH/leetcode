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

S s, t;
unordered_map<char, int> nex;
int main() {
	ifstream fin("inp.in");
	fin >> s >> t;
	nex = {};
	bool yes = false;
	char cur = s[1];
	int ind = 1;
	for (int i = 0; i < int(t.size()); i ++) {
		if (t[i] == cur) {
			ind ++;
			if (ind == int(s.size())) {
				yes = true;
			}
			cur = s[ind];
		}
	}
	db(yes);
	return 0;
}
