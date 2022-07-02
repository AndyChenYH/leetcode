#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define tup tuple
#define mkp make_pair
#define mkt make_tuple
#define rep(act, x) for (int lolol = 0; lolol < x; lolol ++) { act; }
#define fir first
#define sec second
#define E exit(0)
#define F function
#define V vector
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dbl(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out_line(__VA_ARGS__)
#define INF INT_MAX
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

string SS;
string tmpss;
V<string> dict;
int ND;

bool sol() {
    if (SS.empty()) { return true; }
	for (string wd : dict) {
	    for (int i = 0; i < (int) SS.size(); i ++) {
	        for (int ii = i; ii < (int) SS.size(); ii ++) {
	            string sub = string(SS.begin() + i, SS.begin() + ii + 1);
	            if (sub == wd) {
                    db(sub);
	                SS.erase(SS.begin() + i, SS.begin() + ii + 1);
	                bool res = sol();
	                SS = tmpss;
	                if (res) {
	                    return true;
	                }
	            }
	        }
	    }
	}
	return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ifstream fin("inp.in");
	fin >> SS;
	tmpss = SS;
	fin >> ND;
	dict = V<string>(ND);
	sort(dict.begin(), dict.end());
	for (int cc = 0; cc < ND; cc ++) {
		fin >> dict[cc];
	}
    cerr << sol() << endl;
		
	return 0;
}
