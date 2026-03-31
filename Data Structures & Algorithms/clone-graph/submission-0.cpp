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
    unordered_map<Node*, Node*> nodeToCopy;

    Node* dfsCopy(Node* orgNode) {
        Node* copy = new Node(orgNode->val);

        nodeToCopy[orgNode] = copy;

        for (Node* node: orgNode->neighbors) {
            if (nodeToCopy.find(node) != nodeToCopy.end()) {
                copy->neighbors.push_back(nodeToCopy[node]);
            } else {
                copy->neighbors.push_back(dfsCopy(node));
            }   
        }

        return copy;
    }
public:
    Node* cloneGraph(Node* node) {
        return (node) ? dfsCopy(node): nullptr;
    }
};
