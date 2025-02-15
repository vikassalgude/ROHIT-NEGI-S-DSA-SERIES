#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    
    node(int val) {
        data = val;
        left = right = NULL;
    }
};

// LEVEL ORDER TRAVERSAL
vector<int> levelorder(node* root) {
    queue<node*> q;
    q.push(root);
    vector<int> ans;
    node* temp;

    while (!q.empty()) {
        temp = q.front();
        q.pop();
        ans.push_back(temp->data);
        
        if (temp->left) {
            q.push(temp->left);
        }
        
        if (temp->right) {
            q.push(temp->right);
        }
    }
    
    return ans;
}

//COUNT NUMBER OF NODES METHOD 1    
void total(node *root, int& count) {
    if (root == NULL) {
        return;
    }
    count++; // Increment count for each node visited
    total(root->left, count);
    total(root->right, count);
}
//COUNT NUMBER OF NODES METHOD 2
// int countnodes(node *root){
//    if(root==NULL){
//       return 0;
//    }
//    return(1+countnodes(root->left)+countnodes(root->right));
// }

//SUM OF BINARY TREE METHOD 1
int sumofbinarytree(node *root){
   if(root==NULL){
      return 0;
   }
   return(root->data+sumofbinarytree(root->left)+sumofbinarytree(root->right));
}
//SUM OF BINARY TREE METHOD 2
// void total(node *root, int& sum) {
//     if (root == NULL) {
//         return;
//     }
//     sum+=root->data; 
//     total(root->left, sum);
//     total(root->right, sum);
// }

// Function to count the number of leaf nodes in a binary tree.
int total(Node *root, int& count) {
    if ((root->left==NULL)&&(root->right==NULL)) {
        count++; 
        return 0;
    }
    // count++; // Increment count for each node visited
      if (root->left!=NULL){
         total(root->left, count);
      }
      if (root->right!=NULL){
         total(root->right, count);
      }
     
}
// Function to count the number of leaf nodes in a binary tree. method 2
// int count(node *root){
//     if(root==NULL){
//         return 0;
//     }
//     if(!root->left&&!root->right){
//         return 1;
//     }
//     return (count(root->left)+count(root->right));
// }
// the function should return the count of Non-Leaf Nodes
int countNonLeafNodes(Node* root) {
        // Code here
        if(root==NULL)
          return 0;
        if(!root->left&&!root->right){
            return 0;
        }
        return (1+countNonLeafNodes(root->left)+countNonLeafNodes(root->right));
}
//HEIGHT OF BT
int height(Node* node) {
        // code here
        if (node == NULL)
            return 0;
        return 1 + max(height(node->left), height(node->right));
}
//LARGEST VALUE IN EACH LEVEL
vector<int> largestValues(Node* root)
    {
        //code here
        vector<int> ans;
        queue<Node*>q;
        q.push(root);
        
        
        while(!q.empty())
        {
            int n = q.size();
            int maxi = INT_MIN;
            for(int i=0;i<n;i++)
            {
                Node* temp = q.front();
                q.pop();
                maxi = max(temp->data,maxi);
                if(temp->left)
                q.push(temp->left);
                
                if(temp->right)
                q.push(temp->right);
            
            }
            ans.push_back(maxi);
        }
        
        return ans;
    }
int main() {
    // Create a simple binary tree
    /*
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
    */
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // Perform level order traversal
    vector<int> result = levelorder(root);

    // Print the result
    cout << "Level Order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout<<endl;
    // Clean up memory (optional but recommended)
    // Note: In a real application, you should free the allocated memory.
    //COUNT NUMBER OF NODES
    int count=0;
    total(root,count);
    cout<<count<<endl;
    
    return 0;
}
