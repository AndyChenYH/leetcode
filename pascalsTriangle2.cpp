#include "../utils.cpp"
using namespace std;

int main() {
	int n = 2;
	n ++;
	vector<int> a {1, 1};
	for (int i = 2; i < n; i ++) {
		vector<int> row = {1};
		for (int j = 1; j < i; j ++) {
			row.push_back(a[j - 1] + a[j]);
		}
		row.push_back(1);
		a = row;
	}
	db(a);
}
