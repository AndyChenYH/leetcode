#include "../utils.cpp"
#include "LinkedList.cpp"
using namespace std;

int main() {
	ListNode* l = fromV({1, 1, 2, 2, 3, 4, 5, 5, 6});
	ListNode* cur = l;
	while (cur != nullptr && cur->next != nullptr) {
		if (cur->val == cur->next->val) {
			cur->next = cur->next->next;
		}
		else cur = cur->next;
	}
	db(l);
}
