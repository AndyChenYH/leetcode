#include <bits/stdc++.h>
#include "utils.cpp"
#define itr iterator
#define mkt make_trip
#define psb push_back
#define tup tuple
#define mkp make_pair
#define fir first
#define sec second
#define E exit(0)
#define F function
#define V vector
#define bt cerr << "line " << __LINE__ << endl
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define pt(...) pt_out(__VA_ARGS__)
#define INF (2147483647 / 2)
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

struct Vt {
	char vis;
	string wd;
	int cs;
	Vt() {
		vis = 'w';
		cs = INF;
	}
};
ostream& operator << (ostream& out, Vt v) {
	out << v.vis << " " << v.wd << " " << v.cs;
	return out;
}
int NN;
string bw, ew;
V<Vt> vts;
V<V<bool>> mG;
int bfs(int s) {

	queue<int> que;
	que.push(s);
	vts[s].cs = 0;
	vts[s].vis = 'b';
	while (!que.empty()) {
		bool ha = false;
		for (int v = 0; v < NN; v ++) {
			if (mG[que.front()][v] != 0 && vts[v].vis == 'w') {
				ha = true;
				vts[v].vis = 'b';
				vts[v].cs = vts[que.front()].cs + 1;
				if (vts[v].wd == ew) {
					return vts[v].cs;
				}
				que.push(v);
			}
		}
		if (!ha) { que.pop(); }
	}
	return -1;
}
int main() {
	ifstream fin("inp.in");
	fin >> NN >> bw >> ew;
	NN ++;
	vts = V<Vt>(NN, Vt());
	vts[0].wd = bw;
	mG = V<V<bool>>(NN, V<bool>(NN, 0));
	for (int cc = 1; cc < NN; cc ++) {
		fin >> vts[cc].wd;
	}
	auto canGo = [&] (string w1, string w2) {
		assert(w1.size() == w2.size());
		int dd = 0;
		for (int i = 0; i < (int) w1.size(); i ++) {
			if (w1[i] != w2[i]) { dd ++; }
		}
		return dd <= 1;	
	};
	for (int i = 0; i < NN; i ++) {
		for (int ii = 0; ii < NN; ii ++) {
			if (i == ii) { continue; }
			if (canGo(vts[i].wd, vts[ii].wd)) {
				mG[i][ii] = 1;
				mG[ii][i] = 1;
			}
		}
	}
	cerr << bfs(0) + 1 << endl;
	db(NN, bw, ew, plG(vts), pmG(mG));
}
