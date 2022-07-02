#include "../utils.cpp"
using namespace std;

int main() {
	vector<int> a = {1}, b = {};
	int m = 1, n = 0;
	auto sol = [&] () {
		int i = a.size() - 1;
		int l = m - 1, r = n - 1;
		while (i >= 0) {
			if (l == -1) a[i --] = b[r --];
			else if (r == -1 || a[l] > b[r]) {
				a[i --] = a[l --];
			}
			else a[i --] = b[r --];
		}
	};
	sol();
	db(a);
}
