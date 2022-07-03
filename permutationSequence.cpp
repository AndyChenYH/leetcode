#include "../utils.cpp"
using namespace std;

int fact(int n){
	return (n==0) || (n==1) ? 1 : n* fact(n-1);
}

string perm(vector<int> v, int k) {
	if (v.size() == 1) {
		assert(k == 1);
		return string(1, v[0] + '0');
	}
	int fac = fact(v.size());
	int ind = fac / k - 1;
	string dig = string(1, v[ind] + '0');
	v.erase(v.begin() + ind);
	return dig + perm(v, k % (fac / v.size()));
}

int main() {
	string res = perm({1, 2, 3}, 2);
	puts(res.c_str());
}
