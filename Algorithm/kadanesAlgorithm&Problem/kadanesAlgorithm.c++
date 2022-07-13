#include <bits/stdc++.h>
using namespace std;

// Finding max sum of sub array using O(n) using kaden's algorithm

int maxSubArray(int *arr,int size){
    int maxSum = INT_MIN; // 6 
    int currSum = 0;
    for (int i = 0; i < size; i++)
    {
        currSum += arr[i]; 
        if(currSum > maxSum && currSum >=0 ){
            maxSum = currSum;
        }
        if(currSum < 0){
            currSum = 0;
        }

    }
    return maxSum;
    
}

int main()
{
    int arr[15] = {-7, -8, -16, -4, -8, -5, -7, -11, -10, -12, -4, -6, -4, -16, -10 };
    int size = 15;
    int res = maxSubArray(arr,size);
    cout << res << endl;

}