#include <bits/stdc++.h>
using namespace std;

// this question uses tow pinter approach

#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    int left = 0;
    int right = arr.size()-1;
    while(left<=right){
        if(arr[left]+arr[right] == s){

             vector<int> temp;
             temp.push_back(left);
             temp.push_back(right);
             ans.push_back(temp);
             right--;


        }
        if(arr[left]+arr[right] <= s){
            left++;
        }
        else{
            right--;
        }
    }
    return ans;
}

int main()
{
    vector<int>arr = {-2,-3,2,3,3};
    int s = 0;
    vector<vector<int>>ans = pairSum(arr,s);


}