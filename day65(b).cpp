#include<iostream>
using namespace std;

int way(int arr[],int m,int sum){
        if(sum==0)
        return 1;
        if(sum<0)
        return 0;
        int ans =0;
        for(int i=0;i<m;i++){
            ans+=way(arr,m,sum-arr[i]);}
            
        return ans;
    }
int main(){

return 0;
}