//LEFT VIEW OF BINARY TREE METHOD 1
vector<int> leftView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL)
          return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            ans.push_back(q.front()->data);
            while(n--){
                Node* temp=q.front();
                q.pop();
                if(temp->left)
                  q.push(temp->left);
                if(temp->right)
                  q.push(temp->right);
            }
        }
        return ans;
}
//LEFT VIEW OF BINARY TREE METHOD 2 using recursion
void lview(Node* root,int level,vector<int>&ans){
        if(!root){
            return;
        }
        if(level==ans.size()){
            ans.push_back(root->data);
        }
        lview(root->left,level+1,ans);
        lview(root->right,level+1,ans);
}
vector<int> leftView(Node *root) {
        vector<int>ans;
        int level=0;
        lview(root,level,ans);
        return ans;
}

//RIGHT VIEW OF BINARY TREE METHOD 1
vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>ans;
        if(root==NULL)
          return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            ans.push_back(q.front()->data);
            while(n--){
                Node* temp=q.front();
                q.pop();
                if(temp->right)
                  q.push(temp->right);
                if(temp->left)
                  q.push(temp->left);
                
            }
        }
        return ans;
}
//RIGHT VIEW OF BINARY TREE METHOD 2

    void rview(Node* root,int level,vector<int>&ans){
        if(!root){
            return;
        }
        if(level==ans.size()){
            ans.push_back(root->data);
        }
        rview(root->right,level+1,ans);
        rview(root->left,level+1,ans);
        
}
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root){
    vector<int>ans;
    int level=0;
    rview(root,level,ans);
    return ans;
    }
//TOP VIEW OF BT METHOD1
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    void find(Node* root,int pos,int&l,int&r){
        if(!root)
          return;
        l=min(pos,l);
        r=max(pos,r);
        find(root->left,pos-1,l,r);
        find(root->right,pos+1,l,r);
    }
    vector<int> topView(Node *root) {
        // code here
        int l=0,r=0;
        find(root,0,l,r);
        vector<int>ans(r-l+1);
        vector<int>filled(r-l+1,0);
        queue<Node*>q;
        queue<int>index;
        q.push(root);
        index.push(-1*l);
        while(!q.empty()){
            Node *t=q.front();
            q.pop();
            int pos=index.front();
            index.pop();
            if(!filled[pos]){
                filled[pos]=1;
                ans[pos]=t->data;
            }
            if(t->left){
                q.push(t->left);
                index.push(pos-1);
            }
            if(t->right){
                q.push(t->right);
                index.push(pos+1);
            }
        }
        return ans;
    }
};

//TOP VIEW OF BINARY TREE method 2
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    void find(Node* root,int pos,int&l,int&r){
        if(!root)
          return;
        l=min(pos,l);
        r=max(pos,r);
        find(root->left,pos-1,l,r);
        find(root->right,pos+1,l,r);
    }
    void tview(Node* root, int pos, vector<int>& ans, vector<int>& level, int l) {
    if (!root) {
        return;
    }
    if (level[pos] > l) {
        ans[pos] = root->data;
        level[pos] = l;
    }
    tview(root->left, pos - 1, ans, level, l + 1);
    tview(root->right, pos + 1, ans, level, l + 1);
    }

    vector<int> topView(Node *root) {
        // code here
        
        int l=0,r=0;
        find(root,0,r,l);
        vector<int>ans(r-l+1);
        vector<int>level(r-l+1,INT_MAX);
        tview(root,-1*l,ans,level,0);
        return ans;

    }
};

//BOTTOM VIEW OF BT
class Solution {
  public:
   void find(Node* root,int pos,int&l,int&r){
        if(!root)
          return;
        l=min(pos,l);
        r=max(pos,r);
        find(root->left,pos-1,l,r);
        find(root->right,pos+1,l,r);
    }
  
    vector <int> bottomView(Node *root) {
        // Your Code Here
        int l=0,r=0;
        find(root,0,l,r);
        vector<int>ans(r-l+1);
        vector<int>filled(r-l+1,0);
        queue<Node*>q;
        queue<int>index;
        q.push(root);
        index.push(-1*l);
        while(!q.empty()){
            Node *t=q.front();
            q.pop();
            int pos=index.front();
            index.pop();
            
            filled[pos]=1;
            ans[pos]=t->data;
         
            if(t->left){
                q.push(t->left);
                index.push(pos-1);
            }
            if(t->right){
                q.push(t->right);
                index.push(pos+1);
            }
        }
        return ans;
    }
};


    
