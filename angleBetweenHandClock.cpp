#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
	public:
		double angleClock(int hour, int minutes) {
			if (hour == 12) hour = 0;
			double a = 30 * hour + (double) 30 * minutes / 60;
			double b = 6 * minutes;
			printf("%lf %lf\n", a, b);
			double res = abs(a - b);
			return min(res, 360 - res);
		}
};

int main() {
	Solution sol;
	printf("%lf\n", sol.angleClock(7, 35));
	return 0;
}
