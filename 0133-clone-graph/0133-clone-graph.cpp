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
        if(!node) return NULL;

        Node* first= new Node(node->val,{});
        unordered_map<Node* , Node*> mp; 
        mp[node]=first; // so the first node points to the newly created  node
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            // iteratate over the neighbours
            for(auto adj:curr->neighbors){
                if(!mp[adj]){
                    mp[adj]= new Node(adj->val, {});
                    q.push(adj);
                }
                mp[curr]->neighbors.push_back(mp[adj]);
                //mp[curr] will be this newly created node  in line 38
            }
        }

        return mp[node];   
    }
};