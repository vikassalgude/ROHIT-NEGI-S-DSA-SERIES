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

