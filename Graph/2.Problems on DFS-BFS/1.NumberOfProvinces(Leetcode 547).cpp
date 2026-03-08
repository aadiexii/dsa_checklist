#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixToAdjacency(vector<vector<int>> &adjMatrix, int n){
    vector<vector<int>> adjList(n+1);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(adjMatrix[i][j] == 1 && i!= j)
            adjList[i].push_back(j);
        }
    }
    
    return adjList;
}

void dfs(vector<vector<int>> &adjList, int node, vector<int> &vis){
    vis[node] = 1;
    for(auto it: adjList[node]){
        if(!vis[it]){
            dfs(adjList, it, vis);
        }
    }
}

int main(){
    int n; cin >> n;
    vector<vector<int>> adjMatrix(n+1, vector<int> (n+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> adjMatrix[i][j];
        }
    }

    //1.Convert it to adjacency List
    vector<vector<int>> adjList = matrixToAdjacency(adjMatrix, n);

    //2. Do a Traversal and findout the no of provinces
    vector<int> vis(n+1, 0);
    int count = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            count++;
            dfs(adjList, i, vis);
        }
    }


    cout << "The no of Provinces are: " << count << endl;
    return 0;
}