#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 2;
    int m = 2;
    int arr[n][m] = {1,-3,5.4};


}

// 1 -2 
// 1 5 \






int maxSubarraySum(vector<int> arr, int n)
{
     int maxSum = -2147483647;  
     int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i]; 
        if(currSum > maxSum){
            maxSum = currSum;
        }
        if(currSum < 0){
            currSum = 0;
        }

    }
    return maxSum;
    
}

int maxSumRectangle(vector<vector<int>>& mat, int r, int c)
{
    int max_sum = -2147483647;
    for(int i=0; i<r; i++){
        vector<int>v(c);
        for(int j=i; j<r; j++){
            for(int col = 0; col < c; col++){
                v[col] += mat[j][col]; // adding coloums data in column\
            }
//             getting value max value using kadane's algorithm
            int temp = maxSubarraySum(v,c);
            max_sum = max(max_sum,temp);
        }
    }
    return max_sum;
}
