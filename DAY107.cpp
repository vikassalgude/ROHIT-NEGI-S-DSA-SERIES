//PRE ORDER TRAVERSAL ITERATIVE
vector<int> preOrder(Node* root)
    {
        //code here
        stack<Node*>s;
        vector<int>ans;
        s.push(root);
        while(!s.empty()){
            Node* t=s.top();
            s.pop();
            ans.push_back(t->data);
            if(t->right)
             s.push(t->right);
            if(t->left)
             s.push(t->left);
        }
        return ans;
}
//POST ORDER TRAVERSAL ITERATIVE LRN = NRL AND REVERSRE IT
vector<int> postOrder(Node* root) {
        // code here
        stack<Node*>s;
        
        vector<int>ans;
        s.push(root);
        while(!s.empty()){
            Node* t=s.top();
            s.pop();
            ans.push_back(t->data);
            if(t->left)
             s.push(t->left);
            if(t->right)
             s.push(t->right);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
//IN ORDER TRAVERSAL ITERATIVE
vector<int> inOrder(Node* root)
    {
        //code here
        stack<Node*>s;
        stack<bool>visited;
        s.push(root);
        visited.push(0);
        vector<int>ans;
        while(!s.empty()){
            Node* t=s.top();
            s.pop();
            bool flag=visited.top();
            visited.pop();
            if(!flag){
                if(t->right){
                    s.push(t->right);
                    visited.push(0);
                }
                s.push(t);
                visited.push(1);
                if(t->left){
                    s.push(t->left);
                    visited.push(0);
                }
            }
            else{
                ans.push_back(t->data);
            }
        }
        return ans;
    }
