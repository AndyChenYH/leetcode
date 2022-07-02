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
		ListNode* deleteDuplicates(ListNode* l) {
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

			return l;
		}
};
