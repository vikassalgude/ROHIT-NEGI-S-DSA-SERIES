#include<iostream>
#include<queue>
using namespace std;


int findTheWinner(int n, int k) {
    queue<int> q;
    int i=1;
    while(i<=n){
    q.push(i);
    i++;
    }

    while(q.size()!=1){

        int j=1;
        while(j<k){
            int temp=q.front();
            q.push(temp);
            q.pop();
            j++;
        }
        q.pop();
    }
    return q.front();
}