#include <iostream>
#include "../utils.cpp"
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> mt = {
		{1},
		{0},
		{3}
	};
	bool firstRow = find(mt[0].begin(), mt[0].end(), 0) != mt[0].end();
	bool firstCol = false;
	for (int i = 0; i < mt.size(); i ++) {
		for (int j = 0; j < mt[i].size(); j ++) {
			if (mt[i][j] == 0) {
				if (j == 0) firstCol = true;
				mt[i][0] = 0;
				mt[0][j] = 0;
			}
		}
	}
	for (int i = 1; i < mt.size(); i ++) {
		for (int j = 1; j < mt[i].size(); j ++) {
			if (mt[i][0] == 0 || mt[0][j] == 0) {
				mt[i][j] = 0;
			}
		}
	}
	if (firstRow) for (int j = 0; j < mt[0].size(); j ++) mt[0][j] = 0;
	if (firstCol) for (int i = 0; i < mt.size(); i ++) mt[i][0] = 0;
	db(mt);
	/*
	 * solution 1
	unordered_set<int> rows, cols;
	for (int i = 0; i < mt.size(); i ++) {
		for (int j = 0; j < mt[i].size(); j ++) {
			if (mt[i][j] == 0) {
				rows.insert(i);
				cols.insert(j);
			}
		}
	}
	for (int i = 0; i < mt.size(); i ++) {
		for (int j = 0; j < mt[i].size(); j ++) {
			if (rows.find(i) != rows.end() || cols.find(j) != cols.end()) {
				mt[i][j] = 0;
			}
		}
	}
	db(mt);
	*/
}
