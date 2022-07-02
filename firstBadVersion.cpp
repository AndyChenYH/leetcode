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

bool isBadVersion(ll d) {
	return 2126753390 <= d;
}
int main() {
	ll L = 0, R = 1;
	while (!isBadVersion(R)) { 
		R *= 2; 
	}
	ll ans = -1;
	while (L <= R) {
		ll mid = L + (R - L) / 2;
		if (!isBadVersion(mid)) {
			L = mid + 1;	
		}	
		else {
			ans = mid;
			R = mid - 1;	
		}
	}	
	db(ans);
	return 0;
}
