//INTRODUCTION TO TREES|BINARY TREE IN DATA STRUCTURE
//IMPLEMENTED USING QUEUE AND NODE(linked list)
/*Binary Tree Construction using Queue (Level-Order)
This code implements a level-order construction of a binary tree. It leverages a queue data structure and dynamic memory allocation (linked list principles) to build the tree node by node.
Key Concepts:
Node Structure: Each node stores data and pointers to its left and right children.
Queue: A queue holds node pointers, ensuring processing occurs level by level (FIFO).
Dynamic Allocation:
text
new
operator dynamically creates nodes, enabling flexible tree growth.
Level-Order Traversal: The queue-based approach effectively performs a level-order traversal during construction.
Algorithm:
Create a root node and enqueue it.
While the queue is not empty:
Dequeue a node (current node).
Prompt for the left child's data. If not -1, create a new node, link it as the left child, and enqueue it.
Prompt for the right child's data. If not -1, create a new node, link it as the right child, and enqueue it.
The process continues until the queue is empty, resulting in a complete binary tree (based on user input).
In essence, the code simulates a breadth-first traversal during the tree's construction, ensuring that each level is fully populated before moving to the next.*/
#include <iostream>
using namespace std;
#include<queue>
class node{
    public:
    int data;
    node* left,*right;
    node(int v){
        data=v;
        left=right=nullptr;
    }
};
int main() {
    int x;
    cout<<"Enter the root element:"<<endl;
    cin>>x;
    int first,second;
    queue<node*>q;
    node* root=new node(x);
    q.push(root);
    //build the binary tree
    while(!q.empty()){
        node *temp=q.front();
        q.pop();
        //LEFT NODE
        cout<<"Enter left child of "<<temp->data<<"\n";
        cin>>first;
        if(first!=-1){
            temp->left=new node(first);
            q.push(temp->left);
        }
        cout<<"Enter right child of "<<temp->data<<"\n";
        cin>>second;
        if(second!=-1){
            temp->right=new node(second);
            q.push(temp->right);
        }
    }
    

    return 0;
}
//allthe
