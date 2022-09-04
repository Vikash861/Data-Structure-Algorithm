#include <bits/stdc++.h>
using namespace std;

string firstNonRepeating(string str){
    unordered_map<char,int>count;
    queue<int>q;
    string ans = "";
    for (int i = 0; i < str.size(); i++)
    {

    
        char ch = str[i];
        count[ch]++;
        q.push(ch);
        while(!q.empty()){
            char ch = q.front();
            if(count[ch] > 1){
                q.pop();
            }
            else{
                ans.push_back(ch);
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }

    return ans;
}

int main()
{
    string str = "aabc";
    string ans = firstNonRepeating(str);
    cout << ans << endl;
}