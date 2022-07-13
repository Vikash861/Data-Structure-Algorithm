#include <bits/stdc++.h>
using namespace std;

vector<int> hotels(int n, int k, int *a)
{
    int check = 1;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        check = 1;
        for (int j = i + 1; j <= k+i && j < n; j++)
        {
            if (a[i] > a[j])
            {
                check = 1;
            }
            else
            {
                check = 0;
                break;
            }
        }
        if (check == 1)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    vector<int> ans;
    int arr[5] = {4, 7, 2, 3, 1};
    int k = 2;
    int n = 5;
    ans = hotels(n, k, arr);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
}