#include <bits/stdc++.h>
using namespace std;

int flipBits(int* arr, int n) 
{
    int count = 0, count1 = 0, maxCount = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            count++;
            maxCount = max(count,maxCount);
        }
        else{
            count1++;
            count = 0;
        }
    }
    int ans = maxCount + count1;
    return ans;
}



int main()
{
    int arr[5] = {1, 0, 0, 1,0};
    int size = 5;
    cout << flipBits(arr, size);
}


