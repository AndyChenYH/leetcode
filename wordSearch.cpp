#include "../utils.cpp"
using namespace std;


const vector<pair<int, int>> drs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int main() {
	string wd = "A";
	vector<vector<char>> board = {{'A'}};
	int m = board.size(), n = board[0].size();
	vector<vector<bool>> vis(m, vector<bool>(n, false));
	int l = 0;
	auto bd = [&] (int i, int j) {
		return 0 <= i && i < m && 0 <= j && j < n && !vis[i][j];
	};
	function<bool(int, int)> sol = [&] (int i, int j) {
		if (l == wd.size()) return true;
		for (auto p : drs) {
			int ni = i + p.first, nj = j + p.second;
			if (bd(ni, nj) && board[ni][nj] == wd[l]) {
				l ++;
				vis[ni][nj] = true;
				if (sol(ni, nj)) return true;
				vis[ni][nj] = false;
				l --;

			}
		}
		return false;
	};
	bool s = false;
	for (int i = 0; i < m; i ++) for (int j = 0; j < n; j ++) if (sol(i, j)  || string(1, board[i][j]) == wd) s = true;
	printf("%d\n", s);
}