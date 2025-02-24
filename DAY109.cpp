//VERTICAL TRAVERSAL OF BINARY TREE
class Solution {
public:
    void find(Node* root, int pos, int &l, int &r) {
        if (!root) {
            return;
        }
        l = min(pos, l);
        r = max(pos, r);
        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    vector<vector<int>> verticalOrder(Node *root) {
        int l = 0, r = 0;
        find(root, 0, l, r);
        
        vector<vector<int>> positive(r + 1);
        vector<vector<int>> negative(abs(l) + 1);
        
        queue<Node*> q;
        queue<int> index;
        
        q.push(root);
        index.push(0);
        
        while (!q.empty()) {
            Node *temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();
            
            if (pos >= 0) {
                positive[pos].push_back(temp->data);
            } else {
                negative[abs(pos)].push_back(temp->data);
            }
            
            if (temp->left) {
                q.push(temp->left);
                index.push(pos - 1);
            }
            if (temp->right) {
                q.push(temp->right);
                index.push(pos + 1);
            }
        }

        // Combine results
        vector<vector<int>> result;

        // Insert all negative arrays in reverse order
        for (int i = negative.size() - 1; i > 0; i--) {
            result.push_back(negative[i]);
        }

        // Insert all positive arrays in normal order
        for (int i = 0; i < positive.size(); i++) {
            result.push_back(positive[i]);
        }

        return result;
    }
};
// DIAGONAL TREE TRAVERSAL
class Solution {
  public:
    void find(Node *root,int pos,int&l){
        if(!root){
            return;
        }  
        l=max(l,pos);
        find(root->left,pos+1,l);
        find(root->right,pos,l);
        
    }
    void finddiagonal(Node*root,int pos,vector<vector<int>>&ans){
        if(!root){
            return ;
        }
        ans[pos].push_back(root->data);
        finddiagonal(root->left,pos+1,ans);
        finddiagonal(root->right,pos,ans);
        
    }
    vector<int> diagonal(Node *root) {
        // code here
        int l=0;
        find(root,0,l);
        vector<vector<int>>ans(l+1);
        finddiagonal(root,0,ans);\
        vector<int>temp;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                temp.push_back(ans[i][j]);
            }
        }
        return temp;
    }
};
//BOUNDARY TRAVERSAL
class Solution {
  public:
    void leftsubtree(Node*root,vector<int>&ans){
        if(!root||((!root->left)&&(!root->right))){
            return ;
        }
        ans.push_back(root->data);
        if(root->left){
            leftsubtree(root->left,ans);
        }
        else{
            
            leftsubtree(root->right,ans);
        }
        
    }
    void leaf(Node* root,vector<int>&ans){
        if(!root){
            return;
        }
        if(!root->left&&!root->right){
            ans.push_back(root->data);
            return;
        }
        leaf(root->left,ans);
        leaf(root->right,ans);
    }
    void rightsubtree(Node*root,vector<int>&ans){
        if(!root||(!root->left&&!root->right)){
            return ;
        }
        
        if(root->right){
            rightsubtree(root->right,ans);
        }
        else{
            rightsubtree(root->left,ans);
        }
        ans.push_back(root->data);
        
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        ans.push_back(root->data);
        //LEFT SUBTREE
        leftsubtree(root->left,ans);
        //LEAF NODE
        if(root->left||root->right){
          leaf(root,ans);
        }
        //RIGHTSUBTREE
        rightsubtree(root->right,ans);
        
      // ans.pop_back();
        return ans;
    }
};
