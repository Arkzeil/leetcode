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
        if(!node)
            return node;

        Node *clone_node = new Node(node->val);
        mapping[node->val] = clone_node;
        que.push(node);

        while(!que.empty()){
            node = que.front();

            for(int count = 0; count < node->neighbors.size(); count++){
                /*if(!mapping.count(node->val))
                    mapping[node->val] = new Node(node->val);*/

                if(!mapping.count(node->neighbors[count]->val)){
                    mapping[node->neighbors[count]->val] = new Node(node->neighbors[count]->val);
                    que.push(node->neighbors[count]); // put unvisited node into queue
                }

                auto nbr = mapping[node->neighbors[count]->val]; // the neighbor of new node

                if(find(mapping[node->val]->neighbors.begin(), mapping[node->val]->neighbors.end(), nbr) == mapping[node->val]->neighbors.end())
                    mapping[node->val]->neighbors.push_back(nbr); // fill the neighbors of current node

                if(find(nbr->neighbors.begin(), nbr->neighbors.end(), mapping[node->val]) == nbr->neighbors.end())
                    nbr->neighbors.push_back(mapping[node->val]); // make the current node as the neighbor of current node's neighbor
            }

            que.pop();
        }
        return clone_node;
    }
private:
    map<int, Node*> mapping; // for new map
    queue<Node*> que; // for original map
};
