#include <bits/stdc++.h>
using namespace std;

// 2, 10, [10]
// a, b, c
// a < b + c, c > a - b
// b < a + c, c > b - a
// c < a + b, c < a + b
//
// b + c > a
// b - c < a
// c - b < a
//
// b - a < c < a + b
// c < a + b


// linear scan
// fail
int main() {
	//						      i     j  c                    
	vector<int> ar = {4, 5, 6, 7, 9};
	//						0  1  2  3  4  5
	int N = ar.size();
	sort(ar.begin(), ar.end());
	int ct = 0;
	for (int i = 0; i < N - 2; i ++) {
		int c = i + 2;
		for (int j = i + 1; j < N - 1; j ++) {
			for ( ; c < N && ar[i] + ar[j] > ar[c]; c ++);
			ct += c - 1 - j;
			if (c - 1 - j != 0) printf("%d %d %d\n", i, j, c);
		}
	}
	printf("%d\n", ct);
}

/*
// two pointer
int main() {
	vector<int> ar = {2,2,3,4};
	sort(ar.begin(), ar.end());
	int N = ar.size();
	int ct = 0;
	for (int i = N - 1; 1 < i; i --) {
		int l = 0, r = i - 1;
		while (l < r) {
			if (ar[l] + ar[r] > ar[i]) {
				printf("%d %d %d\n", ar[l], ar[r], ar[i]);
				ct += r - l;
				r --;
			}
			else l ++;
		}
	}
	printf("%d\n", ct);
}
*/

/*
// binary search
int main() {
	vector<int> ar = {1, 3, 5, 7, 10};
	sort(ar.begin(), ar.end());
	int N = ar.size();
	int ct = 0;
	for (int i = 0; i < N - 2; i ++) {
		for (int j = i + 1; j < N - 1; j ++) {
			int l = j + 1, r = N - 1, ans = -1;
			while (l <= r) {
				int m = (l + r) / 2;
				if (ar[m] < ar[i] + ar[j]) {
					ans = m;
					l = m + 1;
				}
				else r = m - 1;
			}
			if (ans != -1) ct += ans - j;
		}
	}
	printf("%d\n", ct);
}
*/
