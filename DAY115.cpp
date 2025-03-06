//Lowest Common Ancestor of Binary Search Tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
        return nullptr;
        }
        if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
        }
        else if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
        } 
        else {
        return root; // This is the LCA if p and q are on different sides of root
        }  
    }
};
// BST KEYS IN RANGES
class Solution {
  public:
    void find(Node*root,int n1,int n2,vector<int>&ans){
        if(!root){
            return;
        }
        if(root->data>n1&&root->data>n2){
            find(root->left,n1,n2,ans);
        }
        else if(root->data<n1&&root->data<n2 ){
            find(root->right,n1,n2,ans);
        }
        else{
            find(root->left,n1,n2,ans);
            ans.push_back(root->data);
            find(root->right,n1,n2,ans);
        }
    } 
    vector<int> printNearNodes(Node *root, int low, int high) {
        //code her
        vector<int>ans;
        find(root,low,high,ans);
        return ans;
    }
};
// BST WITH DEAD END
class Solution{
  public:
    bool dead(Node *root,int lower,int upper){
        if(!root){
            return 0;
        }
        if(!root->left&&!root->right){
            if(root->data-lower==1&&upper-root->data==1){
                return 1;
            }
            else return 0;
        }
        return dead(root->left,lower,root->data)||dead(root->right,root->data,upper);
    
    }
    bool isDeadEnd(Node *root)
    {
        
        return dead(root,0,INT_MAX);
        
    }
};
// COMMON NODE IN TWO BST
