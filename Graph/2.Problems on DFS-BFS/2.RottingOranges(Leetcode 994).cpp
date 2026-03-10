#include<bits/stdc++.h>
using namespace std;

//Concept: Grid problem → treat cells as graph nodes → BFS spreads level by level → each level = time

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int> (n));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    } 
    
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(m, vector<int> (n, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 2){
               vis[i][j] = 2;
               q.push({{i, j}, 0});
            }
        }
    }

    int time = 0;
    int dir[4][2] = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        time = q.front().second;
        q.pop();

        for(auto &it: dir){
            int ni = i + it[0];
            int nj = j + it[1];
            int newTime = time + 1;
            if(ni>=0 && ni <m && nj >=0 && nj <n && grid[ni][nj] == 1 && vis[ni][nj]!=2){
                q.push({{ni, nj}, newTime});
                vis[ni][nj] = 2;
            }
        }
    }

    bool ans = false;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(vis[i][j] != 2 && grid[i][j] == 1){
                ans = true;
                break;
            }
        }
    }
    
    ans == true? cout << -1 << endl: cout << time << endl;
    return 0;
}