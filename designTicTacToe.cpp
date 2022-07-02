#include <bits/stdc++.h>
using namespace std;

int main() {
	int N = 3;
	vector<int> rSum[2] = {vector<int>(N, 0), vector<int>(N, 0)};
	vector<int> cSum[2] = {vector<int>(N, 0), vector<int>(N, 0)};
	int fo[2] = {0, 0}, ba[2] = {0, 0};
	function<void(int, int)> bd = [&] (int i, int j) {
		return 0 <= i && i < N && 0 <= j && j < N;
	};
	function<void(int, int, int)> move = [&] (int i, int j, int p) {
		p --;
		rSum[p][i] ++;
		cSum[p][j] ++;
		if (i == j) ba[p] ++;
		if (N - 1 - i == j) fo[p] ++;
		for (int pp = 0; pp < 2; pp ++) {
			if (rSum[pp][i] == N || cSum[pp][j] == N || ba[pp] == N || fo[pp] == N) {
				printf("player %d wins\n", pp + 1);
			}
		}
	};
	move(2, 0, 2);
	move(1, 1, 2);
	move(0, 2, 2);
}
/*
00 01 02
10 11 12
20 21 22
*/

/*
tl t tr
ml m mr
bl b br
*/
