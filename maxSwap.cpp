#include <stdio.h>
#include <algorithm>
using namespace std;

const int MN = 9;
int LN, ar[MN];
pair<int, int> rmq[MN];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &LN);
	for (int i = 0; i < LN; i ++) {
		scanf("%d", &ar[i]);
	}
	rmq[LN - 1] = {ar[LN - 1], LN - 1};
	for (int i = LN - 2; 0 <= i; i --) {
		if (rmq[i + 1].first < ar[i]) {
			rmq[i] = {ar[i], i};
		}
		else {
			rmq[i] = rmq[i + 1];
		}
	}
	for (int i = 0; i < LN - 1; i ++) {
		if (ar[i] < rmq[i + 1].first) {
			swap(ar[i], ar[rmq[i + 1].second]);
			break;
		}
	}
    int res = 0, p = 1;
    for (int i = LN - 1; 0 <= i; i --) {
        res += ar[i] * p;
        p *= 10;
    }
	printf("%d\n", res);
	return 0;
}
