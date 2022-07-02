#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

const int MN = 100000;
int LN, arr[MN + 1];
int main() {
	freopen("inp.in", "r", stdin);
	scanf("%d", &LN);
	for (int i = 0; i < LN; i ++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < LN; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	unordered_multimap<int, int> cur = {};
	unordered_multiset<int> ex = {};
	for (int i = 0; i < LN; i ++) {
		auto f1 = cur.find(arr[i]);
		auto f2 = ex.find(arr[i]);
		if (f1 == cur.end()) {
			if (f2 == ex.end()) {
				cur.insert({arr[i] + 1, 1});
			}
			else {
				ex.erase(arr[i]);
				ex.insert(arr[i] + 1);
			}
		}
		else {
			if (f1->second == 2) {
				ex.insert(f1->first + 1);
			}
			else {
				cur.insert({f1->first + 1, f1->second + 1});
			}
			cur.erase(f1);
		}
	}
	printf("%ld %ld\n", cur.size(), ex.size());
	return 0;
}
