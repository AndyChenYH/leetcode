#include <bits/stdc++.h>
#define V vector
#define db(x) cerr << #x << ": " << x << endl
using namespace std;

int LR, LC;
V<V<int>> mb;
int main() {
	mb = {
		{1, 0, 1, 0, 0},
		{1, 0, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 1, 0},
	};
	LR = mb.size(); 
	LC = mb[0].size();
	for (V<int> v : mb) {
		db(v);
	}
	return 0;
}
