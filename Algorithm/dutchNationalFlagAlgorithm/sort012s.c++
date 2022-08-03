#include <bits/stdc++.h>
using namespace std;

int searchInSorted(int *arr, int key, int s, int e)
{
    if (s > e)
    {
        return -1;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    if (arr[s] <= arr[mid])
    {
        if (key < arr[mid] && key >= arr[s])
        {
            searchInSorted(arr, key, s, mid - 1);
        }
        else
        {
            searchInSorted(arr, key, mid + 1, e);
        }
    }
    else
    {
        if (key >= arr[mid] && key <= arr[e])
        {
            searchInSorted(arr, key, mid + 1, e);
        }
        else
        {
            searchInSorted(arr, key, s, mid - 1);
        }
    }
}

int search(int *arr, int n, int key)
{
    int s = 0;
    int e = n - 1;
    return searchInSorted(arr, key, s, e);
}

int main()
{
    int arr[2] = {3, 1};
    int key = 1;
    cout << search(arr, 2, key) << endl;
}