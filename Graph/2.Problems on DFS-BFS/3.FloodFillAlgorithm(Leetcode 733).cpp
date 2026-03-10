#include <bits/stdc++.h>
using namespace std;

//Concept: Here we are directly asked to return the final grid so we can do it using dfs or bfs as we have not asked thing like min, max etc.
int dr[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; 

void dfs(int m, int n, int src, int sc, int initialColor, vector<vector<int>> &ans, vector<vector<int>> &image, int color){
    ans[src][sc] = color;

    for(auto &it: dr){
        int i = src + it[0];
        int j = sc + it[1];

        if(i>=0 && i<m && j>=0 && j<n && ans[i][j] != color && image[i][j] == initialColor){
            dfs(m,n, i,j, initialColor, ans, image, color);
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> image(m, vector<int> (n));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> image[i][j];
        }
    } 

    int src; cin >> src;
    int sc; cin >> sc;
    int color; cin >> color;
 

    vector<vector<int>> ans = image;
    int initialColor = image[src][sc];
    
    if(initialColor != color){
       dfs(m,n, src,sc, initialColor, ans, image, color);
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << ans[i][j] <<  " ";
        }
        cout << endl;
    }
    return 0;
}