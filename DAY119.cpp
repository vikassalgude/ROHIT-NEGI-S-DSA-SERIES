/* Node is as follows:

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

*/
int getHeight(Node* root) {
    if (!root) return 0; // If the node is null, height is 0
    return root->height; // Return the height of the node
}

// Function to calculate balance factor of a node
int getBalance(Node* root) {
    return getHeight(root->left) - getHeight(root->right); // Balance factor = left height - right height
}

// Right rotation around a subtree rooted with root
Node* rightrotation(Node* root) {
    Node* child = root->left; // Child becomes the left child of root
    Node* childRight = child->right; // Store child's right subtree

    child->right = root; // Perform rotation
    root->left = childRight; // Update left subtree of root

    // Update heights after rotation
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child; // Return new root after rotation
}

// Left rotation around a subtree rooted with root
Node* leftrotation(Node* root) {
    Node* child = root->right; // Child becomes the right child of root
    Node* childLeft = child->left; // Store child's left subtree

    child->left = root; // Perform rotation
    root->right = childLeft; // Update right subtree of root

    // Update heights after rotation
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child; // Return new root after rotation
}


Node* deleteNode(Node* root, int key)
{
    //add code here,
    if(!root)return NULL;
    if(key>root->data){
        root->right=deleteNode(root->right,key);
    }
    else if(key<root->data){
        root->left=deleteNode(root->left,key);
    }
    else{
        //leaf node
        if(!root->left&&!root->right){
            delete root;
            return NULL;
        }
        else if(root->left&&!root->right){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else if(!root->left&&root->right){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else{
            Node* curr=root->right;
            while(curr->left){
                curr=curr->left;
            }
            root->data=curr->data;
            root->right=deleteNode(root->right,root->data);
        }
        
    }
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    int balance=getBalance(root);
    if(balance>1){
        if(getBalance(root->left)>=0){
            return rightrotation(root);
        }
        else{
            root->left=leftrotation(root->left);
            return rightrotation(root);
        }
    }
    else if(balance<-1){
        if(getBalance(root->right)<=0){
           return leftrotation(root);
        }
        else{
            root->right=rightrotation(root->right);
            return leftrotation(root);
        }
    }
    else{
        return root;
    }
}
