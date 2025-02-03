// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
//LINEAR QUEUE  
// class queue{
//     int *arr;
//     int front ,rear;
//     int size;
//     public:
//     queue(int n){
//         size=n;
//         arr=new int [n];
//         front =rear=-1;
//     }
//     bool isempty(){
//         return front ==-1;
//     }
//     bool isfull(){
//         return rear==size-1;
//     }
//     void push(int x){
//         if(isfull()){
//             cout<<"Queue overflow";
//             return;
//         }else if(isempty()){
//             front=rear=0;
//             arr[0]=x;return;
//         }else{
//             rear++;
//             arr[rear]=x;
//             return;
//         }
//     }
//     void pop(){
//         if(isempty()){
//             cout<<"Queue underflow";return;
//         }
//         else{
//             if(front==rear){
//                 front=rear=-1;return;
//             }
//             else{
//                 front++;
//                 return;
//             }
//         }
//     }
//     int start(){
//         if(isempty()){
//             cout<<"Queue is empty";
//             return -1;
//         }
//         else{
//             return arr[front];
//         }
//     }
// };
//CIRCULAR QUEUE
// class queue{
//     int *arr;
//     int front ,rear;
//     int size;
//     public:
//     queue(int n){
//         size=n;
//         arr=new int [n];
//         front =rear=-1;
//     }
//     bool isempty(){
//         return front ==-1;
//     }
//     bool isfull(){
//         return (rear+1)%size==front;
//     }
//     void push(int x){
//         if(isfull()){
//             cout<<"Queue overflow";
//             return;
//         }else if(isempty()){
//             front=rear=0;
//             arr[0]=x;return;
//         }else{
//             rear=(rear+1)%size;
//             arr[rear]=x;
//             return;
//         }
//     }
//     void pop(){
//         if(isempty()){
//             cout<<"Queue underflow";return;
//         }
//         else{
//             if(front==rear){
//                 front=rear=-1;return;
//             }
//             else{
//                 front=(front+1)%size;
//                 return;
//             }
//         }
//     }
//     int start(){
//         if(isempty()){
//             cout<<"Queue is empty";
//             return -1;
//         }
//         else{
//             return arr[front];
//         }
//     }
// };
// QUEUE USING LINKED LIST
class node{
    public:
    int data;
    node *next;
    node(int value){
        data=value;
        next=nullptr;
    }
};
class queue{
    node *front;
    node *rear;
    public:
    queue(){
        rear=front=nullptr;
    }
    bool isempty(){
        return front==NULL;
    }
    void push(int x){
        if(isempty()){
            front=new node(x);
            rear=front;return;
        }
        else{
            rear->next=new node(x);
            rear=rear->next;
        }
    }
    void pop(){
        if(isempty()){
            cout<<"Queue underflw";return;
        }
        else{
            node *temp=front;
            front=front->next;
            delete temp;
        }
    }
    int peek(){
        if(isempty()){
            cout<<"Queue is empty";
            return -1;
        }
        else{
            return front->data;
        }
    }
};
int main() {
    // Write C++ code here
    //std::cout << "Try programiz.pro";
    queue q;
    q.push(1);
    q.push(2);
    cout<<q.peek();
    q.pop();
    q.push(2);
    q.pop();
    cout<<q.peek();
    //q.pop();
    return 0;
}
