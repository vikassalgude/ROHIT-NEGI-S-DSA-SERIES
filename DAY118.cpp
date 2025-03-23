#include <iostream>
using namespace std;

// Definition of the node structure for the AVL tree
class Node {
public:
    Node* right;   // Pointer to the right child
    Node* left;    // Pointer to the left child
    int data;      // Value of the node
    int height;    // Height of the node

    // Constructor to initialize a node
    Node(int x) {
        data = x;
        height = 1;  // New node is initially added at height 1
        left = right = nullptr; // Initialize children to null
    }
};

// Function to get the height of a node
int getHeight(Node* root) {
    if (!root) return 0; // If the node is null, height is 0
    return root->height; // Return the height of the node
}

// Function to calculate balance factor of a node
int getBalance(Node* root) {
    return getHeight(root->left) - getHeight(root->right); // Balance factor = left height - right height
}

// Right rotation around a subtree rooted with root
Node* rightRotation(Node* root) {
    Node* child = root->left; // Child becomes the left child of root
    Node* childRight = child->right; // Store child's right subtree

    child->right = root; // Perform rotation
    root->left = childRight; // Update left subtree of root

    // Update heights after rotation
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child; // Return new root after rotation
}

// Left rotation around a subtree rooted with root
Node* leftRotation(Node* root) {
    Node* child = root->right; // Child becomes the right child of root
    Node* childLeft = child->left; // Store child's left subtree

    child->left = root; // Perform rotation
    root->right = childLeft; // Update right subtree of root

    // Update heights after rotation
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child; // Return new root after rotation
}

// Function to insert a key into the AVL tree and balance it if necessary
Node* insert(Node* root, int key) {
    // If tree is empty, create a new node
    if (!root) {
        return new Node(key);
    }

    // Insert in the appropriate subtree based on key value
    if (key < root->data) { // Insert in left subtree if key is smaller
        root->left = insert(root->left, key);
    } else if (key > root->data) { // Insert in right subtree if key is larger
        root->right = insert(root->right, key);
    } else {
        return root; // Duplicate keys are not allowed, return unchanged node
    }

    // Update height of this ancestor node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check balance factor and perform rotations if necessary
    int balance = getBalance(root);

    // Left Left Case: Right rotation needed
    if (balance > 1 && key < root->left->data) {
        return rightRotation(root);
    }
    
    // Left Right Case: Left rotation followed by right rotation needed
    else if (balance > 1 && key > root->left->data) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    
    // Right Right Case: Left rotation needed
    else if (balance < -1 && key > root->right->data) {
        return leftRotation(root);
    }
    
    // Right Left Case: Right rotation followed by left rotation needed
    else if (balance < -1 && key < root->right->data) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root; // Return the unchanged node pointer after insertion and balancing
}

// Function for inorder traversal of the AVL tree 
void inorderTraversal(Node* root) {
    if (root == nullptr) return; // Base case: empty tree

    inorderTraversal(root->left);   // Traverse the left subtree

    cout << root->data << " ";      // Visit and print the current node

    inorderTraversal(root->right);  // Traverse the right subtree
}

int main() {
    Node* root = nullptr;  // Initialize an empty tree

   /* Insert nodes into AVL tree. Duplicates are not allowed. */
   root = insert(root, 10);
   root = insert(root, 20);
   root = insert(root, 30);
   root = insert(root, 50);
   root = insert(root, 70);
   root = insert(root, 5);
   root = insert(root, 100);
   root = insert(root, 95);

   cout << "Inorder Traversal: ";
   inorderTraversal(root);  // Output the inorder traversal of the AVL tree

   return 0;
}
