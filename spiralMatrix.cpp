#include <iostream>
#include "../utils.cpp"
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	vector<int> res;
	int m = matrix.size(), n = matrix[0].size();
	vector<vector<bool>> vis(m, vector<bool>(n));
	vector<pair<int, int>> drs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int cd = 0;
	int i = 0, j = 0;
	auto bd = [&] (int ii, int jj) {
		return 0 <= ii && ii < m && 0 <= jj && jj < n;
	};
	while (bd(i, j) && !vis[i][j]) {
		res.push_back(matrix[i][j]);
		vis[i][j] = true;
		int ni = i + drs[cd].first;
		int nj = j + drs[cd].second;
		if (!bd(ni, nj) || vis[ni][nj]) {
			cd = (cd + 1) % 4;
		}
		i += drs[cd].first;
		j += drs[cd].second;
	}
	db(res);
}
