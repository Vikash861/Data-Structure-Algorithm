#include <bits/stdc++.h>
using namespace std;
queue<int>interleaving(queue<int>q){
    // step - 1 fetch the half elements from the queue
    int n = q.size()/2;
    stack<int>st;
    while(n>0){
        st.push(q.front());
        q.pop();
        n--;
    }
    // step - 2 push the element into the queue
    while(!st.empty()){
        int elem = st.top();
        st.pop();
        q.push(elem);
    }
    // step - 3 fetch the first half elements from the queue and push again into the queue
    n = q.size()/2;
    while(n>0){
        int elem = q.front();
        q.pop();
        q.push(elem);
        n--;
    }
    
    // step - 4 fetch the first half elements from the queue and put into the stack
    n = q.size()/2;
    while(n>0){
        int elem = q.front();
        q.pop();
        st.push(elem);
        n--;
    }

    
    // step - 5 interleave the elements 
    while(!st.empty()){
        int elemSt = st.top();
        int elemQ =  q.front();
        q.pop();
        st.pop();
        q.push(elemSt);
        q.push(elemQ);
    }


    
    return q;


}
int main()
{
    queue<int>q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(20);
    q.push(30);
    queue<int>ans = interleaving(q);
    while(!ans.empty()){
        cout << ans.front() << endl;
        ans.pop();
    }
}