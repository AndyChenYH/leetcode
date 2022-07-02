#include <bits/stdc++.h>
using namespace std;

// BFS + dp
const int INF = 1e9 + 10;
vector<vector<int>> cost(601, vector<int>(601, INF));
vector<pair<int, int>> drs = {
	{-2, 1},
	{-1, 2},
	{1, 2},
	{2, 1},
	{2, -1},
	{1, -2},
	{-1, -2},
	{-2, -1},
};
bool bound(int i, int j) {
	return 0 <= i && i < 601 && 0 <= j && j < 601;
}
int main() {
	int ti = 5, tj = 5;
	ti += 300;
	tj += 300;
	cost[300][300] = 0;
	list<pair<int, int>> q = {{300, 300}};
	while (!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop_front();
		for (pair<int, int> p : drs) {
			int ni = i + p.first, nj = j + p.second;
			if (bound(ni, nj) && cost[i][j] + 1 < cost[ni][nj]) {
				cost[ni][nj] = cost[i][j] + 1;
				q.push_back({ni, nj});
			}
		}
	}
	printf("%d\n", cost[ti][tj]);
}
