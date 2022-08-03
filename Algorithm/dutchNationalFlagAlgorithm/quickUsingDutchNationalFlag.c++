#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int low  = 0;
    int mid = 0;
    int hight = e;
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cout << "I am in" << endl;
            cnt++;
        }
    }

    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    while(mid <= hight){
        if(arr[mid] == pivot)
    }

    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}
void quickSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
        return;

    // partition
    int p = partition(arr, s, e);
    // do left part sort
    quickSort(arr, s, p - 1);
    // do right par sort
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[19] = {1, 4, 2, 4, 2, 4, 1, 2, 4, 1, 2, 2, 2, 2, 4, 1, 4, 4, 4};
    int n = 19;
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}