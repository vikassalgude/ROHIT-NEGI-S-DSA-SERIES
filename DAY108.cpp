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
// CHECK TREE TRAVERSAL
class Node{
    public:
    int data;
    Node *left,*right;
    
    Node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};
class Solution{
    public:
     int find(int arr[],int start,int end,int x)
    {
        for(int i=start;i<=end;i++)
        {
            if(arr[i]==x)
            return i;
        }
        
        return -1;
    }
     Node *createTree1(int in[],int pre[],int inStart,int inEnd, int index,bool &valid)
    {
        
        if(inStart>inEnd)
        return NULL;
        
        Node *root = new Node(pre[index]);
        
        int pos = find(in,inStart,inEnd,pre[index]);
        
        if(pos==-1)
        {
            valid = 0;
            return NULL;
        }
        
        root->left=createTree1(in,pre,inStart,pos-1,index+1,valid);
        
        
        root->right=createTree1(in,pre,pos+1,inEnd,index+(pos-inStart)+1,valid);
        
        return root;
    }
    
    Node *createTree2(int in[],int post[],int inStart,int inEnd, int index,bool &valid)
    {
        
        if(inStart>inEnd)
        return NULL;
        
        Node *root = new Node(post[index]);
        
        int pos = find(in,inStart,inEnd,post[index]);
        
        if(pos==-1)
        {
            valid = 0;
            return NULL;
        }
        
        root->right=createTree2(in,post,pos+1,inEnd,index-1,valid);
        
        root->left=createTree2(in,post,inStart,pos-1,index-(inEnd-pos+1),valid);
        
        return root;
    }
    
    bool check(Node *root1,Node *root2)
    {
        if(!root1 && !root2)
        return 1;
        
        if(!root1 || !root2)
        return 0;
        
        if(root1->data != root2->data)
        return 0;
        
        return check(root1->left,root2->left) && check(root1->right,root2->right); 
    }
    bool checktree(int pre[], int in[], int post[], int n) 
    { 
    	// Your code goes here
    	bool valid = 1;
    	Node *tree1 = createTree1(in,pre,0,n-1,0,valid);
    	Node *tree2 = createTree2(in,post,0,n-1,n-1,valid);
    	
    	if(!valid)
    	return 0;
    	
    	if(!tree1 || !tree2)
    	return 0;
    	
    	return check(tree1,tree2);
    } 

};
