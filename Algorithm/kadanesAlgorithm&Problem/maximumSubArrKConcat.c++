#include <bits/stdc++.h>
using namespace std;

vector<int> concatArr(vector<int>v, int k){
    vector<int>ans;
    
    int size = v.size()*k;
    int vLen = v.size();
    for (int i = 0; i < size; i++)
    {
        ans.push_back(v[i%vLen]);
    }
    return ans;
    
}

// 1,-2,3,1,-2,3

int maxSubArr(vector<int>v, int k){
    vector<int> concatVec = concatArr(v,k);
    int max = -2147483647;
    int sum = 0;
    for (int i = 0; i < concatVec.size(); i++)
    {
       sum = sum + concatVec[i];
       if(max < sum){
        max = sum;
       }
       if(sum < 0){
        sum = 0;
       }
    }

    return max;
    


}

int main()
{
    vector<int>v;
    v.push_back(1);
    v.push_back(3);
    // v.push_back(1);
    int k = 3;
    int ans = maxSubArr(v,k);
    cout << ans << endl;

// 1 -2  1 -2 -1


    // vector<int> newArr = concatArr(v,k);
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << newArr[i] << " ";
    // }
}