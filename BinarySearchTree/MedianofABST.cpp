#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to count the nodes in the BST using Morris traversal
int countNodes(Node* root) {
    Node* curr = root;
    int count = 0;
    while (curr) {
        if (!curr->left) {
            // Visit node
            count++;
            curr = curr->right;
        } else {
            // Find the inorder predecessor of curr
            Node* pred = curr->left;
            while (pred->right && pred->right != curr) {
                pred = pred->right;
            }
            // Make curr as the right child of its inorder predecessor
            if (!pred->right) {
                pred->right = curr;
                curr = curr->left;
            } else {
                // Revert the changes made in the BST
                pred->right = nullptr;
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}

// Function to find the median of the BST using Morris traversal
float findMedian(Node* root) {
    if (!root) return 0.0;

    int count = countNodes(root); // Total number of nodes in the BST
    int currCount = 0;
    Node* curr = root;
    Node* prev = nullptr;
    Node* first = nullptr, *second = nullptr;

    while (curr) {
        if (!curr->left) {
            // Visit the current node
            currCount++;
            // Check if current node is the median
            if (count % 2 != 0 && currCount == (count + 1) / 2) {
                return curr->data;
            } else if (count % 2 == 0 && currCount == (count / 2)) {
                first = curr;
            } else if (count % 2 == 0 && currCount == (count / 2) + 1) {
                second = curr;
                return (first->data + second->data) / 2.0;
            }
            curr = curr->right;
        } else {
            // Find the inorder predecessor of curr
            Node* pred = curr->left;
            while (pred->right && pred->right != curr) {
                pred = pred->right;
            }
            // Make curr as the right child of its inorder predecessor
            if (!pred->right) {
                pred->right = curr;
                curr = curr->left;
            } else {
                // Revert the changes made in the BST
                pred->right = nullptr;
                currCount++;
                // Check if current node is the median
                if (count % 2 != 0 && currCount == (count + 1) / 2) {
                    return curr->data;
                } else if (count % 2 == 0 && currCount == (count / 2)) {
                    first = curr;
                } else if (count % 2 == 0 && currCount == (count / 2) + 1) {
                    second = curr;
                    return (first->data + second->data) / 2.0;
                }
                curr = curr->right;
            }
        }
    }
    return 0.0; // This line should ideally never be reached.
}

int main() {
    // Example BST
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(10);

    cout << "Median of the BST is: " << findMedian(root) << endl;
    return 0;
}
