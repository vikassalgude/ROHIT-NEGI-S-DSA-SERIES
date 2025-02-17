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
//LEVEL ORDER SPIRAL TRAVERSAL
vector<int> findSpiral(Node* root) {
        // code here
        stack<Node*>s1;
        stack<Node *>s2;
        vector<int>ans;
        s1.push(root);
        while(!s1.empty()||!s2.empty()){
            if(!s1.empty()){
                while(!s1.empty()){
                    Node* temp=s1.top();
                    s1.pop();
                    ans.push_back(temp->data);
                    if(temp->right){
                        s2.push(temp->right);
                    }
                     if(temp->left){
                        s2.push(temp->left);
                    }
                }
            }
            else{
                 while(!s2.empty()){
                    Node* temp=s2.top();
                    s2.pop();
                    ans.push_back(temp->data);
                    if(temp->left){
                        s1.push(temp->left);
                    }
                     if(temp->right){
                        s1.push(temp->right);
                    }
                }
            }
        }
        return ans;
    }
//check if two nodes are cousin
bool isCousins(Node* root, int a, int b) {
    if (root == NULL) return false;
    
    queue<Node*> q;
    q.push(root);
    int l1 = -1, l2 = -1;
    int level = 0;

    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            Node* temp = q.front();
            q.pop();
            // Check if we've found either of the nodes
            if (temp->data == a) l1 = level;
            if (temp->data == b) l2 = level;
            
            // Add children to queue
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        level++;
        // If both nodes are found at different levels, they are not cousins
        if (l1 != l2) return false;

        // If both nodes are found, break out of the loop
        if (l1 != -1 && l2 != -1) break;
    }

    // If the nodes are found at the same level and are not siblings, they are cousins
    return (l1 == l2 && !parent(root, a, b));
}
   
