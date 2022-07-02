#include <bits/stdc++.h>
using namespace std;

const int MN = 1000;
int N, M, di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
bool vis[MN][MN];
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        N = grid.size(), M = grid[0].size();
        memset(vis, false, sizeof(vis));
        int sm = 0;
        function<void(int, int)> dfs = [&] (int i, int j) {
            if (vis[i][j]) return;
            vis[i][j] = true;
            int n = 4;
            for (int d = 0; d < 4; d ++) {
                int ni = i + di[d], nj = j + dj[d];
                if (0 <= ni && ni < N && 0 <= nj && nj < M && grid[ni][nj] == 1) {
                    n --;
                    dfs(ni, nj);
                }
            }
            sm += n;
        };
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j ++) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    return sm;
                }
            }
        }
        return -1;
        
    }
};

int main() {
	vector<vector<int>> grid = {
		{0, 1, 0, 0},
		{1, 1, 1, 0},
		{0, 1, 0, 0},
		{1, 1, 0, 0},
	};
	Solution s;
	int res = s.islandPerimeter(grid);
	printf("%d\n", res);
}
