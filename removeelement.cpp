#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define mkp make_pair
#define T tuple
#define mkt make_tuple
#define rep(act, x) for (int lolol = 0; lolol < x; lolol ++) { act; }
#define fir first
#define sec second
#define E exit(0)
#define F function
#define V vector
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define INF INT_MAX
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int val = 3;
V<int> nums = {2, 3, 3, 3, 5, 10, 3, 15, 20, 4, 3};

int main() {
	for (int i = 0; i < (int) nums.size(); i ++) {
		if (nums[i] == val) {
			nums.erase(nums.begin() + i);
			i --;
		}
	}
	db(nums);

	return 0;
}
