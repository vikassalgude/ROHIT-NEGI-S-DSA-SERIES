// KTH LARGEST LEETCODE
class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>>p;
        for(int i=0;i<k;i++){
            p.push(arr[i]);
        }
        for(int i=k;i<arr.size();i++){
            if(arr[i]>p.top()){
                p.pop();
                p.push(arr[i]);
            }
        }
        return p.top();
    }
};
KTH SMALLEST
class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>p;
        for(int i=0;i<k;i++){
            p.push(arr[i]);
        }
        for(int i=k;i<arr.size();i++){
            if(arr[i]<p.top()){
                p.pop();
                p.push(arr[i]);
            }
        }
        return p.top();
    }
    
};
// Sum of elements between k1'th and k2'th smallest element
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        priority_queue<long long>p1;
        priority_queue<long long>p2;
        for(long long  i=0;i<K1;i++){
            p1.push(A[i]);
        }
        for(long long  i=0;i<K2-1;i++){
            p2.push(A[i]);
        }
        for(long long i=K1;i<N;i++){
            if(A[i]<p1.top()){
                p1.pop();
                p1.push(A[i]);
            }
        }
        for(long long i=K2-1;i<N;i++){
            if(A[i]<p2.top()){
                p2.pop();
                p2.push(A[i]);
            }
        }
        long long h=0;
        long long h1=0;
        while(!p1.empty()){
            h+=p1.top();
            p1.pop();
        }
        while(!p2.empty()){
            h1+=p2.top();
            p2.pop();
        }
        return h1-h;
    }
};
