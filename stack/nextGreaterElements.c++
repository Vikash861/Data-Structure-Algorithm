#include<bits/stdc++.h>
using namespace std;

vector<long long> nextGreaterElements(vector<long long>arr){
    stack<int>ans;
    stack<int>s;
    int end = arr.size()-1;
    for(int i = end; i >= 0; i--) {
        if(s.empty()){
            s.push(arr[i]);
            ans.push(-1);
        }
        else{
            if(arr[i] < s.top()){
                ans.push(s.top());
                s.push(arr[i]);
            }
            else{
                while(!(s.empty()) && arr[i] > s.top()){
                    s.pop();
                }
                if(s.empty()){
                    ans.push(-1);
                    s.push(arr[i]);
                }
                else{
                    ans.push(s.top());
                    s.push(arr[i]);
                }
            }
        }
    }
    vector<long long>res;
    while(!ans.empty()){
        int elem = ans.top();
        ans.pop();
        res.push_back(elem);
    }
    return res;
}

int main(){
    vector<long long>arr{6, 8, 0, 1, 3};
    vector<long long>ans = nextGreaterElements(arr);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

}