#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *fromV(vector<int> v) {
	if (v.empty()) return nullptr;
	ListNode *res = new ListNode(v[0]);
	ListNode *cur = res;
	for (int i = 1; i < (int) v.size(); i ++) {
		cur->next = new ListNode(v[i]);
		cur = cur->next;
	}
	return res;
}

ostream& operator << ( ostream& out, ListNode* l) {
	while (l != nullptr) {
		out << l->val << "৲";
		l = l->next;
	}
	return out;
}
