namespace std {
	int MOD = 1e9 + 7;
	template <typename A, typename H>
		struct hash<pair<A, H>> {
			int operator()( const pair<A, H>& k ) const {
				long long res = 17;
				res = ((res * 31) % MOD + hash<A>()(k.first)) % MOD;
				res = ((res * 31) % MOD + hash<H>()(k.second)) % MOD;
				return int(res % MOD);
			}
		};
}

class Solution {
	public:
		unordered_map<pair<int, int>, int> mem;
		int gen(int lo, int hi) {
			if (mem.find({lo, hi}) != mem.end()) return mem[{lo, hi}];
			if (hi - lo == 0) return 1;
			int res = 0;
			for (int i = lo; i < hi; i ++) {
				int l = gen(lo, i);
				int r = gen(i + 1, hi);
				res += l * r;
			}
			mem.insert({{lo, hi}, res});
			return res;
		}

		int numTrees(int n) {
			return gen(0, n);
		}
};
