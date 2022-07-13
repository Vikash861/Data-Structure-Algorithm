#include <bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;
        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<= size; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }

    void Delete(){
        // replacing first element with last element
        arr[1] = arr[size];
        // decreasing size 
        size--;
        int i = 1;
        while(i < size){
        int leftIndex = 2*i;
        int rightIndex = 2*i+1;
        if(arr[i] < arr[leftIndex] && leftIndex < size){
            swap(arr[i], arr[leftIndex]);
            i = leftIndex;
        }
        else if(arr[i] < arr[rightIndex] && rightIndex < size){
            swap(arr[i], arr[rightIndex]);
            i = rightIndex;
        }
        else{
            return;
        }

        }

    }

};

int main()
{
    heap h1;
    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);
    h1.print();
    h1.Delete();
    h1.print();


}