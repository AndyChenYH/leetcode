#include "../utils.cpp"
using namespace std;

int main() {
	string s = "a ";
	int i = s.size() - 1;
	int d = 0;
	while (s[i] == ' ') {
		i --;
	}
	while (i >= 0 && s[i] != ' ') {
		d ++;
		i --;
	}
	printf("%d\n", d);
}
