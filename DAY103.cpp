// HOW TO CREATE BINARY TREE: METHOD 2
#include <iostream>
using namespace std;

class node {
   public:
   int data;       // Data stored in the node
   node *left,*right;  // Pointers to the left and right children

   // Constructor to initialize a new node
   node(int val){
       data=val;    // Assign the given value to the node's data
       left=right=NULL; // Initialize left and right pointers to NULL (no children initially)
   }
};

// Function to create a binary tree interactively
node* binarytree(){
    int x;
    cin>>x;  // Read input from the user

    // Base case: If the input is -1, it means there is no node (NULL)
    if(x==-1){
        return NULL;
    }

    // Create a new node with the given value
    node *temp=new node(x);

    //LEFT SIDE
    cout<<"Enter the left child of "<<x<<endl;
    temp->left=binarytree();  // Recursively create the left subtree

    //RIGHT SIDE
    cout<<"Enter the right child of "<<x<<endl;
    temp->right=binarytree(); // Recursively create the right subtree

    return temp;  // Return the newly created node
}

int main() {
    cout<<"Enter the root node";
    node* root;   // Pointer to the root of the tree
    root=binarytree(); // Create the binary tree
    return 0;
}
//PRE ORDER TRAVERSAL; gfg
class Solution {
public:
    // Helper function to perform the preorder traversal recursively
    void preorderTraversal(Node* node, std::vector<int>& result) {
        // Base case: if the current node is null, return
        if (node == nullptr) {
            return;
        }

        // 1. Process the current node (add its data to the result)
        result.push_back(node->data);

        // 2. Recursively traverse the left subtree
        preorderTraversal(node->left, result);

        // 3. Recursively traverse the right subtree
        preorderTraversal(node->right, result);
    }

    // Function to return a list containing the preorder traversal of the tree.
    std::vector<int> preorder(Node* root) {
        // Initialize an empty vector to store the preorder traversal result
        std::vector<int> result;

        // Call the helper function to perform the preorder traversal starting from the root
        preorderTraversal(root, result);

        // Return the vector containing the preorder traversal
        return result;
    }
};
//IN ORDER TRAVERSAL GFG
class Solution {
public:
    // Helper function to perform the inorder traversal recursively
    void inorderTraversal(Node* node, std::vector<int>& result) {
        // Base case: if the current node is null, return
        if (node == nullptr) {
            return;
        }

        // 1. Recursively traverse the left subtree
        inorderTraversal(node->left, result);

        // 2. Process the current node (add its data to the result)
        result.push_back(node->data);

        // 3. Recursively traverse the right subtree
        inorderTraversal(node->right, result);
    }

    // Function to return a list containing the inorder traversal of the tree.
    std::vector<int> inOrder(Node* root) {
        // Initialize an empty vector to store the inorder traversal result
        std::vector<int> result;

        // Call the helper function to perform the inorder traversal starting from the root
        inorderTraversal(root, result);

        // Return the vector containing the inorder traversal
        return result;
    }
};
//POST ORDER TRAVERSAL GFG
class Solution {
public:
    // Helper function to perform the postorder traversal recursively
    void postorderTraversal(Node* node, std::vector<int>& result) {
        // Base case: if the current node is null, return
        if (node == nullptr) {
            return;
        }

        // 1. Recursively traverse the left subtree
        postorderTraversal(node->left, result);

        // 2. Recursively traverse the right subtree
        postorderTraversal(node->right, result);

        // 3. Process the current node (add its data to the result)
        result.push_back(node->data);
    }

    // Function to return a list containing the postorder traversal of the tree.
    std::vector<int> postOrder(Node* root) {
        // Initialize an empty vector to store the postorder traversal result
        std::vector<int> result;

        // Call the helper function to perform the postorder traversal starting from the root
        postorderTraversal(root, result);

        // Return the vector containing the postorder traversal
        return result;
    }
};
//LEVEL ORDER TRAVERSAL
vector<int> levelOrder(Node* root)
    {
      //Your code here
      queue<Node*> q;
      q.push(root);
      
      vector<int> ans;
      
      while(!q.empty()){
          Node *temp = q.front();
          q.pop();
          ans.push_back(temp->data);
          if(temp->left)
          q.push(temp->left);
          if(temp->right)
          q.push(temp->right);
      }
      
      return ans;
      
    }

