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
#define WH(x) x.begin(), x.end()
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define INF INT_MAX
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

/*
int K = 4, X = 10;
V<int> arr = {1, 2, 3, 4, 5};
*/
int K, X;
V<int> arr;

pii solp() {
	if (X < arr[0]) {
		return {-1, -1};
	}
	else if (arr[arr.size() - 1] < X) {
		bt;
		return {-2, -2};
	}
	int L = 0, R = arr.size() - 1;
	while (L < R) {
		int mid = L + (R - L) / 2;
		if (arr[mid - 1] <= X && X <= arr[mid + 1]) {
			db(mid);
			return {mid - 1, mid + 1};
		}
		else if (X < arr[mid]) {
			R = mid - 1;
		}
		else if (arr[mid] < X) {
			L = mid + 1;
		}
	}
	throw logic_error("hello world");

}
void sol() { 
	auto inbd = [&] (int i) -> bool {
		return 0 <= i && i < (int) arr.size();
	};	

	pii pos = solp();
	if (pos == mkp(-1, -1)) {
		db(V<int>(arr.begin(), arr.begin() + K));
		return;
	}
	else if (pos == mkp(-2, -2)) {
		db(V<int>(arr.end() - K, arr.end()));
	}
	else {
		int L = pos.fir, R = pos.sec;
		assert(pos.sec - 1 == pos.fir + 1);
		db(pos);
		V<int> res = {arr[pos.sec - 1]};
		assert(L < R);
		while ((int) res.size() < K) {
			if (inbd(L) && inbd(R)) {
				if (X - arr[L] <= arr[R] - X) {
					res.push_back(arr[L]);
					L --;
				}
				else {
					res.push_back(arr[R]);
					R ++;
				}
			}
			else if (!inbd(L)) {
				res.push_back(arr[R]);
				R ++;
			}
			else if (!inbd(R)) {
				res.push_back(arr[L]);
				L --;
			}
		}
		sort(WH(res));
		db(res);
	}
};
int main() {
	ifstream fin("inp.in");
	int NS;
	fin >> K >> X >> NS;
	arr = V<int>(NS);
	for (int cc = 0; cc < NS; cc ++) {
		fin >> arr[cc];
	}
	db(K, X, NS, arr);
	sol();
	return 0;
}
