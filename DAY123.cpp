//HEIGHT OF HEAP
class Solution{
public:
    int helper(int n){
        int ans=0;
        while(n>1){
            n=n/2;
            ans++;
            
        }
        return ans;
    }
    int heapHeight(int N, int arr[]){
        if(N==1)return 1;
        // code here
        return helper(N);
        
    }
};
//Minimum Cost of ropes

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<arr.size();i++){
            q.push(arr[i]);
        }
        int cost=0;
        while(q.size()>1){
            int a=q.top();q.pop();
            int b=q.top();q.pop();
            cost+=a+b;
            q.push(a+b);
         
        }
        
        return cost;
    }
};
// LAST STONE WEIGHT
class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        priority_queue<int>q;
        for(int i=0;i<arr.size();i++){
            q.push(arr[i]);
        }
        //int cost=0;
        while(q.size()>1){
            int a=q.top();q.pop();
            int b=q.top();q.pop();
            //cost+=a-b;
            q.push(a-b);
         
        }
        
        return q.top();
    }
};
