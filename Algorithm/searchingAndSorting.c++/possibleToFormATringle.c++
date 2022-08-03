#include <bits/stdc++.h>
using namespace std;


bool possibleToMakeTriangle(vector<int> &arr)
{

    int size = arr.size();
    if(size < 3){
        return false;
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < size-2; i++){
        if(arr[i] + arr[i + 1] > arr[i + 2])
            return true;
    }
    return false;
}
int main()
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(2);
    cout << possibleToMakeTriangle(arr);



}

// 4 2 1 3 2