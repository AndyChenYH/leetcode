#include "../utils.cpp"
using namespace std;

bool works(int a, int b) {
	assert(a != b);
	int n = a ^ b;
	return !(n != 1 && (n & (n - 1)));
}


int main() {
	int n = 4;
	vector<int> ar;
	for (int i = 0; i < pow(2, n); i ++) {
		ar.push_back(i);
	}
	function<bool(int)> sol = [&] (int i) {
		if (i == ar.size() - 1) {
			if (works(ar[i], ar[i - 1]) && works(ar[i], 0)) {
				return true;
			}
			return false;
		}
		for (int ii = i; ii < ar.size(); ii ++) {
			if (works(ar[i - 1], ar[ii])) {
				swap(ar[ii], ar[i]);
				if (sol(i + 1)) return true;
				swap(ar[ii], ar[i]);
			}
		}
		return false;
	};
	sol(1);
	db(ar);
	for (int i = 0; i < ar.size(); i ++) {
		cout << bitset<4>(ar[i]) << endl;
	}
	puts("");
}
