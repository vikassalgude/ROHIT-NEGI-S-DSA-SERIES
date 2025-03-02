#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node *left,*right;
    node(int val){
        data=val;
        left=right=nullptr;
    }
};
node *insert(node* root,int target){
    if(!root){
        node* temp=new node( target);
        return temp;
    }
    if(target<root->data){
        root->left=insert(root->left,target);
    }
    else{
        root->right=insert(root->right,target);
    }
    return root;
}
node* searchBST(node* root, int val) {
        if(!root){
            return nullptr;
        }
        if(root->data==val){
            return root;
        }
        if(root->data>val){
            return searchBST(root->left,val);
        }
        else{
            return searchBST(root->right,val);
        }
        
}
int main() {
    int arr[]={1,2,3,4,5,11};
    node* root=NULL;
    for(int i=0;i<6;i++){
        root=insert(root,arr[i]);
    }
    cout<<root->right->data;
    return 0;
}
