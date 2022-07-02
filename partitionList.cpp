#include "../utils.cpp"
#include "LinkedList.cpp"
using namespace std;

int main() {
	ListNode *head = fromV({1});
	int x = 3;
auto sol = [&] () {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *l = new ListNode(0), *r = new ListNode(0);
		ListNode *ll = l, *rr = r;
		ListNode *cur = head;
		while (cur != nullptr) {
			if (cur->val < x) {
				l = l->next = new ListNode(cur->val);
			}
			else r = r->next = new ListNode(cur->val);
			cur = cur->next;
		}
		l->next = rr->next;
		return ll->next;
	};
	auto so = sol();
	db(so);
}
