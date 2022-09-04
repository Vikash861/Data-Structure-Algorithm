#include <bits/stdc++.h>
using namespace std;

class Deque{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    Deque(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }
    ///////////////////////////PUSH OPERATION////////////////////////////////////
    void push_front(int value){
        if( ( front == 0 && rear == size-1 ) || (front == rear+1)){
            cout << "queue is full" << endl;
            return;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1){
            front = size-1;
        }
        else{
            front--;
        }
        arr[front] = value;
    }
    void push_back(int value){
        if( ( front == 0 && rear == size-1 ) || (rear == front-1) ){
            cout << "queue is full" << endl;
            return;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if( rear == size-1 && front != 0 ){
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = value;
    }
    ///////////////////////////POP OPERATION////////////////////////////////////

    int pop_front(){
        if( front == -1 ){
            cout << "que is empty" << endl;
            return -1;
        }
        else{
            int data = arr[front];
            arr[front] = -1;
            if(front == rear){
                front = rear = -1;
            }
            else if(front == size-1){
                front = 0;
            }
            else{
                front++;
            }
            return data;
        }
    }

    int pop_back(){
        if( front == -1 ){
            cout << "que is empty" << endl;
            return -1;
        }
        else{
            int data = arr[rear];
            arr[rear] = -1;
            if(front == rear){
                front = rear = -1;
            }
            else if(rear == 0){
                rear = size-1;
            }
            else{
                rear--;
            }
            return data;
        }
    }

    int getFront(){
        if(front == -1)
            return -1;
        else
            return arr[front];
    }

    int getRear(){
        if(rear == -1)
            return -1;
        else
            return arr[rear];
    }

};


int main()
{
    Deque dque(5);
    dque.push_front(30);
    cout << dque.pop_front() << endl;
    cout << dque.getRear() << endl;
    // dque.push_front(45);
    // dque.push_front(40);
    // dque.push_back(89);
    // dque.push_back(90);
    // cout << dque.getFront() << endl;
    //  cout << dque.getRear() << endl;
    // cout << dque.pop_front() << endl;
    // cout << dque.pop_front() << endl;
    // cout << dque.pop_front() << endl;
    // cout << dque.pop_front() << endl;
    // cout << dque.pop_front() << endl;
    // cout << dque.pop_front() << endl;

}
