#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int k){
    deque<int>maxi;
    deque<int>mini;
    int sum = 0;
    for(int i = 0; i < k; i++){
        if(maxi.empty() && mini.empty()){
            maxi.push_back(arr[i]);
            mini.push_back(arr[i]);
        }
        else{
            int mElem = maxi.front();
            int miElem = mini.front();
            if(arr[i] > mElem){
                maxi.pop_front();
                maxi.push_back(arr[i]);
            }
            if(arr[i] < miElem){
                mini.pop_front();
                mini.push_back(arr[i]);
            }
        }
    }
    sum = maxi.front() + mini.front();
    return sum;
}

int main(){
    int arr[7] = {2,5,-1,7,-3,-1,-2};
    int n = 7;
    int k = 4;
    cout << solve(arr,n,k) << endl;
}