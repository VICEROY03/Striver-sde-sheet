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
public:
    Node* dfs(Node* n, unordered_map<int, Node*> &mark){
        if(mark.find(n->val)!=mark.end()){
            return mark[n->val];
        }
        Node* n1 = new Node(n->val);
        mark[n->val] = n1;
        for(Node* x: n->neighbors)
            (n1->neighbors).push_back(dfs(x, mark));
        return n1;
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<int, Node*> mark;
        return dfs(node, mark);
    }
};