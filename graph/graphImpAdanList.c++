#include <bits/stdc++.h>
using namespace std;




int main()
{
    int v; // node or vertices
    cout << "Enter Number of Nodes" << endl;
    cin >> v;
    int e;
    cout << "Enter Number of Edges" << endl;
    cin >> e;
    vector<int>g[v];
    for(int i = 0; i < e; i++){
        int n1, n2;
        cout << "Enter node 1 and node 2 to connect" << endl;
        cin >> n1 >> n2;
        g[n1].push_back(n2);
        g[n2].push_back(n1);
    }
    // graph made using adjacency matrix

    // printing graph 

    for(int i = 0; i < v; i++){
        cout << i << " -> ";
        for(auto j:g[i]){
            cout << j;
        }
        cout << endl;
    }



}