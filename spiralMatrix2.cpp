#include <iostream>
#include "../utils.cpp"
#include <vector>
using namespace std;

int main() {
	int n = 4;
	vector<vector<int>> matrix(n, vector<int>(n));
	vector<pair<int, int>> drs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int i = 0, j = 0;
	auto bd = [&] (int ii, int jj) {
		return 0 <= ii && ii < n && 0 <= jj && jj < n;
	};
	int c = 1;
	int cd = 0;
	while (bd(i, j) && matrix[i][j] == 0) {
		matrix[i][j] = c ++;
		int ni = i + drs[cd].first;
		int nj = j + drs[cd].second;
		if (!bd(ni, nj) || matrix[ni][nj] != 0) {
			cd = (cd + 1) % 4;
		}
		i += drs[cd].first;
		j += drs[cd].second;
	}
	db(matrix);
}
