#include <bits/stdc++.h>
using namespace std;

//We are using 1 Based Indexing. In case of 0-based indexing we need to 
vector<int> bfsTraversal(vector<int> &PrintBfs, vector<vector<int>> &adjacencyList, int n, int m){
    vector<int> vis(n+1, 0);
    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while(!q.empty()){
    int node = q.front();
        q.pop();
        PrintBfs.push_back(node);

        for(auto it: adjacencyList[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
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
    bfsTraversal(PrintBfs, adjacencyList, n, m);

    for(int i=0; i<PrintBfs.size(); i++){
        cout << PrintBfs[i];
    }
    return 0;
}