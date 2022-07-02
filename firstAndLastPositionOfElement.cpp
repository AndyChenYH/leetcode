#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define psb push_back
#define mkp make_pair
#define mkt make_trip
#define fir first
#define sec second
#define thi third
#define E exit(0)
#define F function
#define V vector
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define MOD 1000000007
#define printf(args...) fprintf(stderr, ##args)
#define INF (2147483647 / 2)
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef string S;

int main() {
	int tar = 7;
	V<int> arr = {7,7,7,7,7,7,7,7,7};
	int L = 0, R = arr.size() - 1;
	// finding right pos
	while (L <= R) {
		int mid = L + (R - L) / 2;	
		if (arr[mid] == tar && (mid == (int) arr.size() - 1 || arr[mid + 1] != tar)) { 
			db(mid);
			break; 
		}
		else if (tar < arr[mid]) {
			R = mid - 1;	
		}
		else if (arr[mid] <= tar) {
			L = mid + 1;
		}
	}
	L = 0, R = arr.size() - 1;
	while (L <= R) {
		int mid = L + (R - L) / 2;
		if (arr[mid] == tar && (mid == 0 || arr[mid - 1] != tar)) {
			db(mid);
			break;
		}
		else if (arr[mid] < tar) {
			L = mid + 1;
		}
		else if (tar <= arr[mid]) {
			R = mid - 1;
		}
	}
}
