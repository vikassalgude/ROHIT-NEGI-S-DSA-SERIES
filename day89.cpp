#include <iostream>
using namespace std;
class stack{
    int *arr;
    int size;
    int top;
    public:
    stack(int s){
        size=s;
        top=-1;
        arr=new int [size];
    }
    void push(int val){
        if(top==size-1){
            cout<<"stack overflow\n";//return;
        }else{
            top++;arr[top]=val;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"stack underflow\n";
        }else{
            top--;
        }
    }
    int peek(){
        if(top==-1){
            cout<<"stack underflow\n";return 0;
        }else{ return arr[top];
    }}
    bool isempty(){
        if(top==-1)return true;
        else return false;
    }
    bool isfull(){
        if(top==size-1)return true;
        else return false;
    }
    int size(){
        return top+1;
    }
};
int main() {
    stack s(3);
    cout<<s.isempty();
    s.push(1);s.push(2);s.push(3);s.push(4);
    cout<<s.peek();s.pop();cout<<s.peek();cout<<s.isfull();

    return 0;
}
