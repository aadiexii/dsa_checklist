#include <bits/stdc++.h>
using namespace std;

//We are using 1 Based Indexing. In case of 0-based indexing we need to 
vector<int> dfsTraversal(vector<int> &PrintBfs, vector<vector<int>> &adjacencyList, int n, int m, int node, vector<int> &vis){
    vis[node] = 1;
    PrintBfs.push_back(node);

    for(auto it: adjacencyList[node]){
        if(!vis[it]){
            dfsTraversal(PrintBfs, adjacencyList, n, m, it, vis);
        }
    }
    return PrintBfs;
}

int main() {
    int n;
    int m; 
    cin >> n; cin >> m;

    vector<vector<int>> adjacencyList(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    vector<int> PrintBfs;
    int start = 1;
    vector<int> vis(n+1, 0);
    dfsTraversal(PrintBfs, adjacencyList, n, m, start, vis);

    for(int i=0; i<PrintBfs.size(); i++){
        cout << PrintBfs[i] << " ";
    }
    return 0;
}