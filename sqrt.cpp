#include <iostream>
#include <float.h>
using namespace std;

int main() {
	int x = 46;
	double l = 1, r = 2;
	while (r * r < x) r *= 2;
	while (l + 0.001 < r) {
		double m = (r + l) / 2;
		if (m * m < x) l = m;
		else r = m;
	}
	printf("%d\n", (int) r);
}
