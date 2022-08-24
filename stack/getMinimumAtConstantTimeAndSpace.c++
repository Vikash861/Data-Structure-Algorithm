#include<bits/stdc++.h>
using namespace std;

class SpecialStack {
    // Define the data members.
    stack<int>s;
    int mini;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:    
    void push(int data) {
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data > mini){
                s.push(data);
            }
            else{
                s.push(2*data-mini);
                mini = data;
            }
        }
    }

    int pop() {
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        s.pop();
        if(curr > mini)
            return curr;
        else{
            int prevMini = mini;
            int val = 2*mini-curr;
            mini = val;
            return prevMini;
        }
    }

    int top() {
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        if(curr < mini){
            return mini;
        }
        else{
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty()){
            return -1;
        }
        else{
            return mini;
        }
    }  
};


int main(){
    SpecialStack st;
    st.push(5);
    cout << st.getMin() << endl;
    st.push(3);
    cout << st.getMin() << endl;
}