#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> que;
    que.push_front(11);
    cout << que.front() << endl;
    que.push_back(15);
    cout << que.size() << endl;
    cout << que.back();
    que.pop_front();
    cout << que.front() << endl;
    que.pop_front();
    if(que.empty()){
        cout << "que is empty" << endl;
    }
    else{
        cout << "que is not empty" << endl;
    }
}
