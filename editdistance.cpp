#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define mkp make_pair
#define T tuple
#define mkt make_tuple
#define rep(act, x) for (int lolol = 0; lolol < x; lolol ++) { act; }
#define fir first
#define sec second
#define E exit(0)
#define F function
#define V vector
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define INF INT_MAX / 2
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

string wd1 = "horse";
string wd2 = "ros";

int main() {
    V<V<int>> test = {
            {1, 2, 3, 4, 5},
            {4, 4, 3, 9, 5},
            {8, 2, 8, 5, 5},
            {7, 2, 7, 1, 5},

    };
    F<int(int, int)> sol = [&] (int i1, int i2) -> int {
        if (i1 == 0) {
            return i2;
        }
        else if (i2 == 0) {
            return i1;
        }
        if (wd1[i1] == wd2[i2]) {
            return sol(i1 - 1, i2 - 1);
        }
        int ins = sol(i1, i2 - 1);
        int dele = sol(i1 - 1, i2);
        int rep = sol(i1 - 1, i2 - 1);
        return 1 + min(ins, dele, rep);
    };
    cerr << sol(wd1.size() - 1, wd2.size() - 1) << endl;

	return 0;
}
