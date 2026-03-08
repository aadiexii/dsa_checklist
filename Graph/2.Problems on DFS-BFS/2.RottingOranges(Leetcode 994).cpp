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

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> adjMatrix(m+1, vector<int> (n+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> adjMatrix[i][j];
        }
    } 

    //1.Convert it to adjacency List
    vector<vector<int>> adjList = matrixToAdjacency(adjMatrix, n);
}