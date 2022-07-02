#include "../utils.cpp"
using namespace std;

int main() {
	vector<int> ar = {2,0,2,1,1,0};
	int a = 0, b = ar.size() - 1;
	for (int i = 0; i <= b; ) {
		if (ar[i] == 0) {
			swap(ar[i ++], ar[a ++]);
		}
		else if (ar[i] == 2) {
			swap(ar[i], ar[b --]);
		}
		else i ++;
	}
	db(ar);
}
