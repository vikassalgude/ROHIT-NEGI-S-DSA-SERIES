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

//TOP VIEW OF BINARY TREE



    
