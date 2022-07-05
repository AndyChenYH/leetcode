/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
	public:
		ListNode* middleNode(ListNode* l) {
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
			return r;
		}
};
