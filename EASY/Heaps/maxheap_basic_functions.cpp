//Basic Functions of Max heap

#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    int *heapArray;
    int capacity;
    int heapSize;
    public:
        //Constructor
        MaxHeap(int capacity){
            heapSize = 0;
            heapArray = new int[capacity];
            capacity = capacity;
        }
        //Utilities
        int parent(int i) {return (i-1)/2;}
        int left(int i) {return (2*i+1);}
        int right(int i) {return (2*i+2);}
        void printArray(){
            for(int i=0;i<heapSize;i++) cout<<heapArray[i]<<" ";
            cout<<endl;
        }

        //Inserts the val at the end
        void insertKey(int key){
            if(heapSize > capacity) {
                cout<<"Overflow"<<endl;
                return;
            }
            heapSize++;
            int i = heapSize -1;
            heapArray[i] = key;
            while(i!=0 && heapArray[parent(i)]<heapArray[i]){
                swap(heapArray[parent(i)],heapArray[i]);
                i = parent(i);
            }
        }

        //heapifies a subtree with the root at given index
        void maxHeapify(int index){
            int l = left(index);
            int r = right(index);
            int greatest = index;
            if(l<heapSize && heapArray[l]>heapArray[index]) greatest = l;
            if(r<heapSize && heapArray[r]>heapArray[greatest]) greatest = r;
            if(greatest != index){
                swap(heapArray[greatest],heapArray[index]);
                maxHeapify(greatest);
            }
        }

        //Reduces val at index with new value
        void decreaseKey(int index,int new_val){
            heapArray[index] = new_val;
            while(index!=0 && heapArray[parent(index)]<heapArray[index]){
                swap(heapArray[parent(index)],heapArray[index]);
                index = parent(index);
            }
        }

        //Deletes the min element and returns
        int extractMax(){
            if(heapSize == 0) {cout<<"Heap is Empty"<<endl;return INT_MAX;}
            if(heapSize == 1) {heapSize--;return heapArray[0];}
            int root = heapArray[0];
            heapArray[0] = heapArray[heapSize-1];
            heapSize--;
            maxHeapify(0);
            return root;
        }

        //Deletes element at index
        void deleteAtIndex(int k){
            decreaseKey(k,INT_MAX);
            extractMax();
        }
};

int main(){
    MaxHeap mh(4);
    mh.insertKey(4);
    mh.insertKey(2);
    mh.insertKey(1);
    mh.insertKey(0);
    mh.printArray();
    mh.deleteAtIndex(1);
    mh.printArray();
}