//Sorted Linked List to BST

class Solution {
  public:
    TNode * createbst(vector<int>&tree,int start,int end){
        if(start>end)return NULL;
        int mid=start+(end-start+1)/2;
        TNode* root=new TNode(tree[mid]);
        root->left=createbst(tree,start,mid-1);
        root->right=createbst(tree,mid+1,end);
        return root;
        
    }
    TNode *sortedListToBST(LNode *head) {
        // code here
        vector<int>tree;
        while(head){
            tree.push_back(head->data);
            head=head->next;
        }
        
        return createbst(tree,0,tree.size()-1);
    }
    
};
//Merge two BST 's
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inOrderTraversal(Node* root,vector<int>& result) {
    if (root == nullptr) return;
    inOrderTraversal(root->left, result);
    result.push_back(root->data);
    inOrderTraversal(root->right, result);
    }
    vector<int> merge(Node *root1, Node *root2) {
        vector<int>ans1;
        vector<int>ans2;
        inOrderTraversal(root1,ans1);
        inOrderTraversal(root2,ans2);
        int i=0;int j=0;
        vector<int>ans;
        while(i<ans1.size()&&j<ans2.size()){
            if(ans1[i]<ans2[j]){
                ans.push_back(ans1[i++]);
            }
            else{
                ans.push_back(ans2[j++]);
            }
        }
        while(i<ans1.size()){
            ans.push_back(ans1[i++]);
        }
        while(j<ans2.size()){
            ans.push_back(ans2[j++]);
        }
        return ans;
    }
};
