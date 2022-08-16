#include<bits/stdc++.h>
using namespace std;

void print(map<int,string>m){
        for(auto &pr:m){
        cout << pr.first << " " << pr.second << endl;
    }
}

int main(){
    map<int,string> m;
    m[4] = "ghi";
    m.insert({1,""});
    m.insert({2,"abc"});
    m.insert({3,"def"});
    // map<int,string>::iterator it; // declering iterator

    // for(it = m.begin(); it != m.end(); ++it){
    //     cout << (*it).first << " " << (*it).second<< endl;
    // }
    for(auto &pr:m){
        cout << pr.first << " " << pr.second << endl;
    }
    auto it = m.find(7);
    /*
    if(it == m.end()){
        cout << "No values in map"<< endl;
    }
    else{
        cout << (*it).first << " " << (*it).second << endl;
    }
    */
//    deleting pair form map 
// using iterator 
    if(it != m.end()){
        m.erase(it);
    }
// using direact
    m.erase(3);
    print(m);
   
}