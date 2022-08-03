#include <bits/stdc++.h>
using namespace std;



int removeElement(vector<int>& nums, int val) {
    int sz = nums.size();
    int j = sz-1;
    if(sz == 0 || sz == 1 && nums[0] == val)
        return 0;
    int i  = 0;
    while(i < j){
        if(i < sz && nums[i] != val)
            i++; 
        if(j > -1 &&nums[j] == val)
            j--;
        if(j<i)
            break;
        swap(nums[i++], nums[j++]);    

    }
    return j+1;
}
 
// 0 0 1 2 2 2 3 4
// 2,2,3,3
//       2

int main()
{
    vector<int>v = {3,2,2,3};
    int val = 3;
    int ans = removeElement(v,val);
    cout << ans << endl;
    for(int i = 0; i <= v.size(); i++)
        cout << v[i] << ' ';


}

