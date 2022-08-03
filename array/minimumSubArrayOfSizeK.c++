#include <bits/stdc++.h>
using namespace std;

int maxSubArraySizeK(int arr[],int n, int k){
    int i = 0,j = 0,mini = INT_MAX,sum=0;
    while(j<n){
        if(j-i+1 < k){
            sum += arr[j];
            j++;
        }
        else if(j-i+1 == k){
        sum = sum+arr[j];
        mini = min(mini,sum);
        sum = sum-arr[i];
        i++;
        j++;
        }

        
    }

    return mini;
}

int main()
{
    int arr[] = {100,200,300,400};
    int k = 2,n=4;
    cout << maxSubArraySizeK(arr,n,k) << endl;

}