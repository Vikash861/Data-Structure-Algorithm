#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top;
    Stack(int size){
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data){
        if(top >= size-1){
            cout << "stack is overflow";
            return;
        }
        top++;
        cout << top << endl;
        arr[top] = data;
    }

    void pop(){
        if(top == -1){
            cout << "stack is uderflow" ;
            return;
        } 

        top--;

    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    void peak(){
        if(top == -1){
            cout << "no element exist" << endl;
            return ;
        }
        cout << arr[top] << endl;
    
    }

};

int main()
{
    // stack<int>s;
    // s.push(10);
    // s.push(20);
    // s.pop();
    // cout << s.size() << endl;

    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(13);
    st.push(40);
    st.push(50);
    if(st.isEmpty()){
        cout << "Stack is Empty" << endl;
    }
    else{
        cout << "Stack is not empty" << endl;
    }
    st.peak();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.peak();

}