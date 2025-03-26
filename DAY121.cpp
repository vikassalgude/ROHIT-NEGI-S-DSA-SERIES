#include <iostream>
using namespace std;
class MaxHeap{
    
    int *arr;
    int size;//total elements in heap
    int total_size;//total size of array
    public: 
    MaxHeap(int n){
        arr=new int[n];
        size=0;
        total_size=n;
    }
    //insert into the heap
    void insert(int value){
        //if heap size is available or not
        if(size==total_size){
            cout<<"Heap Overflow\n";
            return;
        }
        arr[size]=value;
        int index=size;
        size++;
        //Compare it with its parent
        while(index>0&&arr[(index-1)/2]<arr[index]){
            swap(arr[(index-1)/2],arr[index]);
            index=(index-1)/2;
        };
        cout<<arr[index]<<" is inserted into the heap\n";
        
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    void Heapify(int x){
        int largest=x;
        int left=2*x+1;
        int right=2*x+2;
        //Largest will store the index of the element which is greater between parent,left child andright child
        if(left<size&&arr[left]>arr[largest]){
            largest=left;
        }
        if(right<size&&arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=x){
            swap(arr[x],arr[largest]);
            Heapify(largest);
        }
        
    }
    void Delete(){
        if(size==0){
            cout<<"Heap UnderFlow\n";
            return;
        }
        cout<<arr[0]<<" deleted from the heap\n";
        arr[0]=arr[size-1];
        size--;
        if(size==0){
            return;
        }
        Heapify(0);
    }
    
};
int main() {
    MaxHeap H1(6);
    H1.insert(4);
    H1.insert(14);
    H1.insert(11);
    H1.insert(114);
    H1.insert(24);
    H1.insert(1);
    H1.insert(10);
    H1.Delete();
    H1.print();
    return 0;
}
