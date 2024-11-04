class Solution {
public:
    void fillNodesSet(Node* root, unordered_set<int>& nodes) {
        if (root == NULL) {
            return;
        }
        nodes.insert(root->data);
        fillNodesSet(root->left, nodes);
        fillNodesSet(root->right, nodes);
    }

    bool checkDeadEnd(Node* root, unordered_set<int>& nodes) {
        if (root == NULL) {
            return false;
        }

        // Dead end condition: if node is a leaf and both `node - 1` and `node + 1` exist in the set
        if (root->left == NULL && root->right == NULL) {
            if (nodes.find(root->data - 1) != nodes.end() && nodes.find(root->data + 1) != nodes.end()) {
                return true;
            }
        }

        // Recursively check left and right subtrees for dead ends
        return checkDeadEnd(root->left, nodes) || checkDeadEnd(root->right, nodes);
    }

    bool isDeadEnd(Node* root) {
        unordered_set<int> nodes;
        nodes.insert(0);  // Adding 0 to handle edge cases with 1 as root
        fillNodesSet(root, nodes);
        return checkDeadEnd(root, nodes);
    }
};