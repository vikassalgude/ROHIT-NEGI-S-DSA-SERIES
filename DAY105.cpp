// Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        // Your Code 
        if(!r1&&!r2){
            return 1;
        }
        if((!r1&&r2)||(!r2&&r1)){
            return 0;
        }
        if(r1->data!=r2->data){
            return 0;
        }
        return (isIdentical(r1->left,r2->left)&&isIdentical(r1->right,r2->right));
    }
// Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        // code here
        if(root==NULL){
            return;
        }
        Node *temp=root->right;
        root->right=root->left;
        root->left=temp;
        mirror(root->left);
        mirror(root->right);
        
    }
 //BALANCE TREE CHECK
  int height(Node *root,bool &valid){
        if(!root){
            return 0;
        }
        int l=height(root->left,valid);
        int r=height(root->right,valid);
        if(abs(l-r)>1){
            valid=0;
        }
        return (1+max(l,r));
    }
    bool isBalanced(Node* root) {
        // Code here
        bool valid=1;
        height(root,valid);
        return valid;
    }
   
