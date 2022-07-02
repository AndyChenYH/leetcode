#include "../utils.cpp"
#include "LinkedList.cpp"
using namespace std;

int main() {
	ListNode* l = fromV({1, 1});
	l = new ListNode(-200, l);
	auto sol = [&] () {
		ListNode* cur = l;
		assert(cur != nullptr);
		// size less than 3
		if (cur->next == nullptr || cur->next->next == nullptr) return;
		while (cur->next != nullptr && cur->next->next != nullptr) {
			if (cur->next->val == cur->next->next->val) {
				while (cur->next->next != nullptr && cur->next->val == cur->next->next->val) {
					cur->next->next = cur->next->next->next;
				}
				cur->next = cur->next->next;
			}
			else {
				cur = cur->next;
			}
		}

	};
	sol();
	l = l->next;
	db(l);
}
