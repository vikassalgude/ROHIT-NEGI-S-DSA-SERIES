 #include <iostream>
 using namespace std;
class node{
    public:
    int data;
    node* next;
    node *prev;
    node(int value){
        data=value;
        next=prev=NULL;
    }
};
//USING RECURSION
node * createdll(int arr[],int index,int size,node*back){
    if(index==size)return NULL;
    node*temp=new node(arr[index]);
    temp->next=createdll(arr,index+1,size,temp);
    return temp;
}
node* insertAtPosition(node* head, int pos, int value) {
    // Edge cases
    if (pos == 0) { // Insert at the beginning
        node* newNode = new node(value);
        if (head == NULL) {
            return newNode; // List was empty
        } else {
            newNode->next = head;
            head->prev = newNode;
            return newNode; // New head
        }
    } else {
        node* curr = head;
        while (--pos && curr != NULL) { // Traverse to the desired position
            curr = curr->next;
        }

        // If we reached the end of the list
        if (curr == NULL) { 
            cout << "Position out of bounds." << endl;
            return head; // Return unchanged list
        }

        // Insert at the end
        if (curr->next == NULL) {
            node* newNode = new node(value);
            curr->next = newNode;
            newNode->prev = curr;
        } else { // Insert in the middle
            node* newNode = new node(value);
            newNode->next = curr->next;
            newNode->prev = curr;

            curr->next->prev = newNode; // Update previous link of next node
            curr->next = newNode; // Link current to new node
        }
    }
    return head; // Return the possibly updated head
}

int main() {
//     node *head=NULL;
//     // insert at start
//     // LL doesn't exits
//     // if(head==NULL){
//     //     head=new node(5);
//     // }
//     // else{
//     //     node *temp=new node(5);
//     //     temp->next=temp;
//     //     head->prev=head;
//     //     head=temp;
//     // }
//     // ARRAY TO LINKED LIST
    // node* head = NULL;
    // node* tail = NULL;

    // // Array to Linked List
    // int arr[] = {1, 2, 3, 4}; // Fixed missing semicolon
    // int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // for (int i = 0; i < size; i++) { // Use size instead of hardcoded 5
    //     if (head == NULL) {
    //         head = new node(arr[i]);
    //         tail = head;
    //     } else {
    //         node* temp = new node(arr[i]);
    //         tail->next = temp; // Link the new node
    //         temp->prev = tail; // Set the previous pointer of the new node
    //         tail = temp; // Move tail to the new node
    //     }
    // }
    int arr[] = {1, 2, 3, 4};
    node* head=createdll(arr,0,4,NULL);
     
     
    //insertion at any points
     int pos=2;
    
    //     //edge cases
    // if(pos==0){
    //         //DLL empty
    //     if(head==NULL){
    //             head=new node(9);
    //     }
    //     else{
    //         node *temp=new node(9);
    //         temp->next=head;
    //         head->prev=temp;
    //         head=temp;
    //         }
    // }
    // else{
    //     node *curr=head;
    //     while(--pos&&curr!=NULL){
    //             curr=curr->next;
    //     }
    //         //end points
    //     if(curr->next=NULL){
    //         node *temp=new node(9);
    //         temp->prev=curr;
    //         curr->next=temp;
    //     }
    //         // at middle
    //     else{
    //              node *temp=new node(9);
    //              temp->next=curr->next;
    //              temp->prev=curr;
    //              curr->next=temp;
    //              temp->next->prev=temp;     
                       
                
    //         }
            
    // }
    head = insertAtPosition(head, pos, 9);

    
    
    
    node* trav = head;
    while (trav) {
        cout << trav->data << " "; // Added space for better readability
        trav = trav->next;
    }
    
    cout << endl; // Print newline after the list

    return 0;
 }
