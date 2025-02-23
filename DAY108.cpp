class Solution {
  public:
    int find(vector<int>in,int target,int start,int end){
        for(int i=start;i<=end;i++){
            if(in[i]==target){
                return i;
            }
        }
        return -1;
    }
    Node *tree(vector<int>in,vector<int>pre,int instart,int inend,int index){
        if(instart>inend){
            return NULL;
        }
        Node* root=new Node(pre[index]);
        int pos=find(in,pre[index],instart,inend);
        root->left=tree(in,pre,instart,pos-1,index+1);
        root->right=tree(in,pre,pos+1,inend,index+1+(pos-instart));
        return root;
        
    }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &in, vector<int> &pre) {
        // code here
        int n=in.size();
        return tree(in,pre,0,n-1,0);
    }
};

class Solution {
  public:
        int find(vector<int>in,int target,int start,int end){
        for(int i=start;i<=end;i++){
            if(in[i]==target){
                return i;
            }
        }
        return -1;
    }
       Node *tree(vector<int>in,vector<int>post,int instart,int inend,int index){
        if(instart>inend){
            return NULL;
        }
        Node* root=new Node(post[index]);
        int pos=find(in,post[index],instart,inend);
        root->right=tree(in,post,pos+1,inend,index-1);
        root->left=tree(in,post,instart,pos-1,index-(inend-pos)-1);
        
        return root;
        
    }

    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> in, vector<int> post) {
        // code here
        int n=in.size();
        return tree(in,post,0,n-1,n-1);
    }
};
