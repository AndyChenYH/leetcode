#include "../utils.cpp"
#include "LinkedList.cpp"
using namespace std;

int main() {
	ListNode *l = fromV({1});
	auto sol = [&] () {
		if (l->next == nullptr) return l;
		ListNode *cur = l->next, *mid = l;
		int i = 1, m = 0;
		while (cur != nullptr) {
			if (m < i / 2) {
				m ++;
				mid = mid->next;
				assert(m == i / 2);
			}
			i ++;
			cur = cur->next;
		}
		if (i % 2 == 0) mid = mid->next;
		return mid;
	};
	ListNode *r = sol();
	printf("%d\n", r->val);
}
