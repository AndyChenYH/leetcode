
class Solution {
	public:
		Node* cloneGraph(Node* node) {
			if (node == nullptr) return nullptr;
			// seen clones; use for setting neighbours
			vector<Node*> seen(101, nullptr);
			Node* clone = new Node(node->val);
			list<pair<Node*, Node*>> st;
			st.push_back({node, clone});
			seen[node->val] = clone;
			while (!st.empty()) {
				auto fr = st.front(); st.pop_front();
				Node *no = fr.first, *c = fr.second;
				for (Node* nei : no->neighbors) {
					// attach existing neighbours
					if (seen[nei->val] != nullptr) {
						c->neighbors.push_back(seen[nei->val]);
						continue;
					}
					// create clone neighbour
					Node* cn = new Node(nei->val);
					c->neighbors.push_back(cn);
					st.push_back({nei, cn});
					seen[cn->val] = cn;
				}
			}
			return clone;
		}
};
