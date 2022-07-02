#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define psb push_back
#define tup tuple
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define E exit(0)
#define F function
#define V vector
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define pt(...) pt_out(__VA_ARGS__)
#define INF INT_MAX / 2
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define MN 100

int NI, nums[MN];
int main() {
	ifstream fin("inp.in");
	fin >> NI;
	for (int cc = 0; cc < NI; cc ++) {
		fin >> nums[cc];
	}
	int ii = 0;
	for (int i = 0; i < NI - 2; ) {
		if (nums[i] == nums[i + 1] && nums[i] == nums[i + 2]) {
			nums[ii] = nums[i];
			nums[ii + 1] = nums[i];
			i += 3;
			ii += 2;
		}
		else {
			nums[ii] = nums[i];
			i ++;
			ii ++;
		}
	}
	NI = ii;
	db(V<int>(nums, nums + NI));
}
