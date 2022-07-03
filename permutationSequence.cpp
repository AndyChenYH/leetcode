#include "../utils.cpp"
using namespace std;

int fact(int n){
	return (n==0) || (n==1) ? 1 : n* fact(n-1);
}

string perm(vector<int> v, int k) {
	db(v, k);
	if (v.size() == 2) {
		assert(k <= 2);
		if (k == 1) return string(1, v[0] + '0') + string(1, v[1] + '0');
		else return string(1, v[1] + '0') + string(1, v[0] + '0');
	}
	int fac = fact(v.size());
	int ind = fac / k - 1;
	string dig = string(1, v[ind] + '0');
	vector<int> nv = v;
	nv.erase(nv.begin() + ind);
	return dig + perm(nv, k % (fac / v.size()));
}

int main() {
	string res = perm({1, 2, 3, 4}, 9);
	puts(res.c_str());
}
