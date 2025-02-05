#include <iostream>
#include <queue>
using namespace std;
void display(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main() {
    int arr[5]={1,2,3,4,5};
    int n=5;
    int k=3;
    queue<int>q;
    for(int i=0;i<k-1;i++){
        q.push(arr[i]);
    }
    for(int i=k-1;i<5;i++){
        q.push(arr[i]);
        display(q);
        q.pop();
    }
    

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;
void display(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main() {
    int arr[5]={1,2,3,4,5};
    int n=5;
    int k=3;
    queue<int>q;
    for(int i=0;i<k-1;i++){
        q.push(arr[i]);
    }
    for(int i=k-1;i<5;i++){
        q.push(arr[i]);
        display(q);
        q.pop();
    }
    

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;
void display(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main() {
    int arr[5]={1,2,3,4,5};
    int n=5;
    int k=3;
    queue<int>q;
    for(int i=0;i<k-1;i++){
        q.push(arr[i]);
    }
    for(int i=k-1;i<5;i++){
        q.push(arr[i]);
        display(q);
        q.pop();
    }
    

    return 0;
}
class Solution {
  public:
    // int display(queue<int>q){
    //     while(!q.empty()){
    //         if(q.front()<0){
    //             return q.front();
    //         }
    //         q.pop();
    //     }
    //     return 0;
    // }
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        queue<int>q;
        vector<int>ans;
        // for(int i=0;i<k-1;i++){
        //     q.push(arr[i]);
        // }
        // for(int i=k-1;i<arr.size();i++){
        //     q.push(arr[i]);
        //     int a=display(q);
        //     ans.push_back(a);
        //     q.pop();
        // }
        // return ans;
        for(int i=0;i<k-1;i++){
            if(arr[i]<0){
                q.push(i);
            }
        }
        for(int i=k-1;i<arr.size();i++){
            if(arr[i]<0){
                q.push(i);
                
            }
            if(q.empty()){
                ans.push_back(0);
            }
            else{
                if(q.front()<=i-k){
                    q.pop();
                }
                if(q.empty()){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(arr[q.front()]);
                }
            }
        }
        return ans;
    }
};

//THIRD QUESTION
// string B="";
    // vector<int>r(26,0);
    // queue<char>q;
    // for(int i=0;i<A.size();i++){
    //   if(r[A[i]-'a']>=1){
    //       r[A[i]-'a']++;
    //       while(!q.empty()&&r[q.front()-'a']>1){
    //           q.pop();
    //       }
    //       if(q.empty()){
    //       B+='#';}
    //       else{
    //           B+=q.front();
    //       }
    //   }
    //   else{
    //       r[A[i]-'a']++;
    //       q.push(A[i]);
    //       while(!q.empty()&&r[q.front()-'a']>1){
    //           q.pop();
    //        }
         
    //        B+=q.front();
    //   }
    // }
    // return B;
