#include "../utils.cpp"
using namespace std;

class Node {
	public:
		int val;
		Node* next;
		Node* random;

		Node(int _val) {
			val = _val;
			next = NULL;
			random = NULL;
		}
};
ostream& operator << ( ostream& out, Node* l) {
	if (l == nullptr) {
		out << "nullptr";
		return out;
	}
	while (l != nullptr) {
		out << l->val;
		if (l->random != nullptr) out << "," << l->random->val;
		out << "৲";
		l = l->next;
	}
	return out;
}

int main() {
	/*
	Node* a = new Node(7), *b = new Node(13), *c = new Node(11), *d = new Node(10), *e = new Node(1);
	a->next = b; b->next = c; c->next = d; d->next = e;
	b->random = a; c->random = e; d->random = c;
	*/
	Node* a = new Node(7), *b = new Node(13);
	a->next = b; 
	b->random = a;
	Node* n = a;
	// first loop weaving the randoms
	Node* cur = n;
	while (cur != nullptr) {
		Node* nc = new Node(cur->val);
		nc->next = cur->next;
		cur->next = nc;
		cur = cur->next->next;
	}
	cur = n;
	Node* res = n->random;
	while (cur != nullptr) {
		// the next point is the clone
		Node* clone = cur->next;
		// setting up the random of clone
		if (cur->random == nullptr) clone->random = nullptr;
		else clone->random = cur->random->next;
		cur = cur->next;
	}

	db(res);
}
