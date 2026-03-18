#include<bits/stdc++.h>
using namespace std;

void matrixToAdjacencyList(vector<vector<int>> &adjacencyMatrix, int n){
    vector<vector<int>> adjacencyList(n+1);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(adjacencyMatrix[i][j] == 1 && i!=j){
                adjacencyList[i].push_back(j);
                // NOTE: For undirected graphs, do NOT add adjacencyList[j].push_back(i) inside
                // the conversion loop. The matrix already stores both directions:
                //    adjacencyMatrix[u][v] = 1
                //    adjacencyMatrix[v][u] = 1
                // So the loop will naturally pick up both directions on its own.
                // Adding the reverse manually inside the loop will cause DUPLICATES.
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout << i << "->";
        for(auto it: adjacencyList[i]){
            cout << it << " ";
        }
        cout << endl;
    }
}
int main(){
    //n -> no of nodes
    //m -> no of edges
    int n, m;
    cin >> n >> m;

    //For 1-Based we use n+1.
    vector<vector<int>> adjacencyMatrix(n+1, vector<int> (n+1, 0));;
    for(int i=0; i<m; i++){
       int u, v;
       cin >> u >> v;
       adjacencyMatrix[u][v] = 1;
       adjacencyMatrix[v][u] = 1; //Remove this in case of directed-graph
    }

    matrixToAdjacencyList(adjacencyMatrix, n);
    return 0;
}