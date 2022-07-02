/*
 *
 * 1 5 8 4 7 6 5 3 1
 * 1 5 8 4 7 6 5 3 1
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> ar = {1, 5, 1};
	int N = ar.size();
	for (int i = N - 2; 0 <= i; i --) {
		if (ar[i] < ar[i + 1]) {
			for (int j = i + 1; j < N; j ++) {
				if (j == N - 1) {
					if (ar[j] > ar[i]) {
						swap(ar[i], ar[j]);
						break;
					}
				}
				if (ar[j] <= ar[i]) {
					swap(ar[i], ar[j - 1]);
					break;
				}
			}
			reverse(ar.begin() + i + 1, ar.end());
			break;
		}
	}
	for (int d : ar) printf("%d ", d);
	puts("");
}
