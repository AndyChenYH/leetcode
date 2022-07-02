#include "../utils.cpp"
using namespace std;

/*
 * solution 1
vector<vector<int>> combine(int n, int k) {
	if (k == 0) return {{}};
	assert(n >= k);
	vector<vector<int>> res = {};
	// use cur
	for (vector<int> v : combine(n - 1, k - 1)) {
		v.push_back(n);
		res.push_back(v);
	}
	// don't use cur
	if (n > k) {
		for (vector<int> v : combine(n - 1, k)) {
			res.push_back(v);
		}
	}
	return res;
}
*/
vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> res;
	vector<int> v;
	for (int i = 1; i <= k; i ++) {
		v.push_back(i);
	}

	v.push_back(n + 1);
	while (true) {
		db(v);
		bool b = true;
		for (int i = k; 1 <= i; i --) {
			if (v[i] != v[i - 1] + 1) {
				v[i - 1] ++;
				b = false;
				res.push_back(vector(v.begin(), v.begin() + (v.size() - 1)));
				break;
			}
		}
		if (b) break;
	}
	return res;
}
int main() {
	int n = 4, k = 2;
	auto res = combine(n, k);
	db(res);
}