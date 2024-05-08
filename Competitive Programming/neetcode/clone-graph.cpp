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
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*> visited;
        Node* clone = new Node(node->val);
        visited[node] = clone;
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* first = q.front();
            Node* second = visited[first];
            q.pop();
            for(auto x: first->neighbors){
                if(visited.find(x) == visited.end()){
                    Node* child = new Node(x->val);
                    visited[x] = child;
                    second->neighbors.push_back(child);
                    q.push(x);
                }
                else{
                    second->neighbors.push_back(visited[x]);
                }
            }
        }

        return clone;
    }
};