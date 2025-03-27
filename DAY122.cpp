#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// void Heapify(int arr[],int index,int n){
//     int largest=index;
//     int left=2*index+1;
//     int right=2*index+2;
//     if(left<n&&arr[left]>arr[largest]){
//         largest=left;
//     }
//     if(right<n&&arr[right]>arr[largest]){
//         largest=right;
//     }
//     if(largest!=index){
//         swap(arr[largest],arr[index]);
//         Heapify(arr,largest,n);
//     }
// }
void Heapify(int arr[], int index, int n) {
    int largest = index;
    
    while (true) {
        int left = 2 * largest + 1; // left child index
        int right = 2 * largest + 2; // right child index
        // // Check if left child exists and is greater than current largest
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        // Check if right child exists and is greater than current largest
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        // If the largest is still the index, we are done
        if (largest == index) {
            break;
        }
        // Swap and continue heapifying
        swap(arr[largest], arr[index]);
        // Move down to the largest index
        index = largest;
    }
}

//MIN HEAP
// void Heapify(int arr[],int index,int n){
//     int largest=index;
//     int left=2*index+1;
//     int right=2*index+2;
//     if(left<n&&arr[left]<arr[largest]){
//         largest=left;
//     }
//     if(right<n&&arr[right]<arr[largest]){
//         largest=right;
//     }
//     if(largest!=index){
//         swap(arr[largest],arr[index]);
//         Heapify(arr,largest,n);
//     }
// }
void BuildMaxHeap(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        Heapify(arr,i,n);
    }
    
}
void SortArray(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        Heapify(arr,0,i);
    }
    
}
void printHeap(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
    int arr[]={10,3,8,9,5,13,18,14,11,70};
    BuildMaxHeap(arr,10);
    printHeap(arr,10);
    priority_queue<int>p;
    p.push(10);
    p.push(11);
    p.push(9);
    cout<<"\n"<<p.top();
    
    return 0;
}
