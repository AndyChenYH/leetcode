#include "../utils.cpp"
using namespace std;

int fact(int n){
	return (n==0) || (n==1) ? 1 : n* fact(n-1);
}

string perm(vector<int> v, int k) {
	if (v.size() == 1) {
		return string(1, v[0] + '0');
	}
	int fac = fact(v.size());
	int ind = k / (fac / v.size()) + 1; 
	string dig = string(1, v[ind] + '0');
	db(fac, v, k, dig);
	vector<int> nv = v;
	nv.erase(nv.begin() + ind);
	return dig + perm(nv, k % (fac / v.size()));
}

int main() {
	string res = perm({1, 4}, 1);
	puts(res.c_str());
}
