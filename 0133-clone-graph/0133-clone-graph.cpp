/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* dfs(Node* node, unordered_map<Node*, Node*> &mp){
        Node* clone = new Node(node->val);

        vector<Node*> nei;
        mp[node] = clone;
        for(auto it: node->neighbors){
            if(mp.find(it) != mp.end())
                nei.push_back(mp[it]);
            else
                nei.push_back(dfs(it, mp));
        }
        clone -> neighbors = nei;
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;

        if(node == NULL) return nullptr;

        if(node->neighbors.size() == 0){
            Node* cloned = new Node(node->val);
            return cloned;
        }
        return dfs(node, mp);
    }
};