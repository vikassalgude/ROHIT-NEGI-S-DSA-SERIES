//Construct Binary Search Tree from Preorder Traversal
class Solution {
public:
    TreeNode *bst(vector<int>&preorder,int& index,int lower,int upper){
        if(index==preorder.size()||preorder[index]<lower||preorder[index]>upper){
            return NULL;
        }
        TreeNode *root=new TreeNode(preorder[index++]);
        root->left=bst(preorder,index,lower,root->val);
        root->right=bst(preorder,index,root->val,upper);
        return root;


    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        TreeNode* root=bst(preorder,index,INT_MIN,INT_MAX);
        return root;
    }
};
//BST FROM POST ORDER
Node *bst(int post[],int&index,int lower,int upper){
    if(index<0||post[index]<lower||post[index]>upper){
            return NULL;
        }
        Node *root=new Node(post[index--]);
        root->right=bst(post,index,root->data,upper);
        root->left=bst(post,index,lower,root->data);
        return root;

}

Node *constructTree (int post[], int size)
{
//code here
int index=size-1;
Node* root=bst(post,index,INT_MIN,INT_MAX);
return root;
}

//pre order and bst
class Solution {
  public:
    void bst(int arr[],int&index,int lower,int upper,int N){
        if(index==N||arr[index]<lower||arr[index]>upper){
            return ;
        }
        
        int value=arr[index++];
        bst(arr,index,lower,value,N);
        bst(arr,index,value,upper,N);
        
        
    }
    
    int canRepresentBST(int arr[], int N) {
        // code here
        int index=0;
        bst(arr,index,INT_MIN,INT_MAX,N);
        return index==N;
    }
    
};
