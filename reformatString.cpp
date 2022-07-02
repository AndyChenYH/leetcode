#include <stdio.h>
#include <math.h>
#include <string.h>

const int MS = 100000;
int LS, ld, lc, lr;
char s[MS + 1], dig[MS + 1], ch[MS + 1], res[MS + 1];
int main() {
	freopen("inp.in", "r", stdin);
	scanf("%s", s);
	LS = strlen(s);
	for (int i = 0; i < LS; i ++) {
		if ('a' <= s[i] && s[i] <= 'z') {
			ch[lc ++] = s[i];
		}
		else {
			dig[ld ++] = s[i];
		}
	}
	if (abs(ld - lc) <= 1) {
		if (ld == lc) {
			for (int i = 0; i < ld; i ++) {
				res[lr ++] = dig[i];
				res[lr ++] = ch[i];
			}
		}
		else if (ld < lc) {
			res[lr ++] = ch[0];
			for (int i = 0; i < ld; i ++) {
				res[lr ++] = dig[i];
				res[lr ++] = ch[i + 1];
			}
		}
		else {
			res[lr ++] = dig[0];
			for (int i = 0; i < lc; i ++) {
				res[lr ++] = ch[i];
				res[lr ++] = dig[i + 1];
			}
		}
	}
	printf("%s\n", res);

	return 0;
}
