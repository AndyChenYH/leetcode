#include "../utils.cpp"
using namespace std;

int main() {
	int n = 5;
	vector<vector<int>> res = {{1}, {1, 1}};
	for (int i = 2; i < n; i ++) {
		vector<int> row = {1};
		for (int j = 1; j < i; j ++) {
			row.push_back(res.back()[j - 1] + res.back()[j]);
		}
		row.push_back(1);
		res.push_back(row);
	}
	db(res);
}
