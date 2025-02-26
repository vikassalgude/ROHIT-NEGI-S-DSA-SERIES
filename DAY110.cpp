//MORRIS INORDER TRAVERSAL
class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        
        vector<int>ans;
        while(root){
            if(!root->left){
                ans.push_back(root->data);
                root=root->right;
            }
            else{
                Node* curr=root->left;
                while(curr->right&&curr->right!=root){
                    curr=curr->right;
                }
                if(curr->right==NULL){
                    curr->right=root;
                    root=root->left;
                }
                else{
                    curr->right=NULL;
                    ans.push_back(root->data);
                    root=root->right;
                }
                
            }
        }
        return ans;
    }
};
//MORRIS PREORDER TRAVERSAL
class Solution{
    public:
    vector<int> preOrder(Node* root)
    {
        vector<int>ans;
        while(root){
            if(!root->left){
                ans.push_back(root->data);
                root=root->right;
            }
            else{
                Node* curr=root->left;
                while(curr->right&&curr->right!=root){
                    curr=curr->right;
                }
                if(curr->right==NULL){
                    ans.push_back(root->data);
                    curr->right=root;
                    root=root->left;
                }
                else{
                    curr->right=NULL;
                   
                    root=root->right;
                }
                
            }
        }
        return ans;
    }
};
// MORRIS POST ORDER TRAVERSAL
class Solution{
    public:
    vector<int> postOrder(Node* root) {
        // code here

        vector<int>ans;
        while(root){
            if(!root->right){
                ans.push_back(root->data);
                root=root->left;
            }
            else{
                Node* curr=root->right;
                while(curr->left&&curr->left!=root){
                    curr=curr->left;
                }
                if(curr->left==NULL){
                    ans.push_back(root->data);
                    curr->left=root;
                    root=root->right;
                }
                else{
                    curr->left=NULL;
                    
                    root=root->left;
                }
                
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
