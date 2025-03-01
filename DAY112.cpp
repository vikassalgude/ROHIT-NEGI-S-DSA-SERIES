//CHECK BST
class Solution {
  public:
    // void inorder(Node *root,vector<int>&ans){
    //     if(!root){
    //         return;
    //     }
    //     inorder(root->left,ans);
    //     ans.push_back(root->data);
    //     inorder(root->right,ans);
    // }
    // Function to check whether a Binary Tree is BST or not.
    bool valid(Node* root,int&prev){
        if(!root){
            return 1;
        }
        bool l=valid(root->left,prev);
        if(l==0){
            return 0;
        }
        if(root->data<prev){
            return 0;
        }
        prev=root->data;  
        return valid(root->right,prev);
    }
    bool isBST(Node* root) {
        // Your code here
        // vector<int>ans;
        // inorder(root,ans);
        // for(int i=0;i<ans.size()-1;i++){
        //     if(ans[i]>ans[i+1]){
        //         return 0;
        //     }
        // }
        // return 1;
        int prev=INT_MIN;
        return valid(root,prev);
    }
};
//MINIMUM DISTANCE BETWEEN BST NODES
class Solution {
public:
    void inorder(TreeNode *root,vector<int>&ans){
        if(!root){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    int minDiffInBST(TreeNode* root) {
       vector<int>ans;
        inorder(root,ans);
        int result=INT_MAX;
        for(int i=0;i<ans.size()-1;i++){
            int diff=ans[i+1]-ans[i];
            result=min(result,diff);
        } 
        return result;
    }
};
//SUM OF K SMALLEST ELEMENT IN BST
void ksum(Node*root,int&sum,int&k){
    if(!root){
        return;
    }
    ksum(root->left,sum,k);
    k--;
    if(k>=0){
        sum+=root->data;
    }
    if(k<=0){
        return;
    }
    ksum(root->right,sum,k);
}
int sum(Node* root, int k) 
{ 
  
    // Your code here
    int sum=0;
    ksum(root,sum,k);
    return sum;
    
    
} 
//Kth LARGEST ELEMENT IN BST
class Solution {
  public:
    void largest(Node*root,int&ans,int&k){
        if(!root){
            return;
        }
        largest(root->right,ans,k);
        k--;
        if(k==0){
            ans=root->data;
            return;
        }
        
        
        largest(root->left,ans,k);
    }
    int kthLargest(Node *root, int k) {
        // Your code here
        int ans=0;
        largest(root,ans,k);
        return ans;
    }
};
