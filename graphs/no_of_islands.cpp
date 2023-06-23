
// //no of islands in a graph using bfs

#include <bits/stdc++.h>
using namespace std;

int bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();
    vector<int> dr{-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dc{-1, 0, 1, -1, 1, -1, 0, 1};
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        // Traverse the neighbors and mark them
        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == '1') {
                q.push({nr, nc});
                vis[nr][nc] = 1;
            }
        }
    }
}

int noOfIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (!vis[row][col] && grid[row][col] == '1') {
                bfs(row, col, vis, grid);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, '0'));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        grid[u][v] = '1';
        grid[v][u] = '1';
    }
    int res = noOfIslands(grid);
    cout << "Number of islands: " << res << endl;

    return 0;
}

// #include<bits/stdc++.h>

// using namespace std;

// int bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&  grid){
//     vis[row][col]=1;
//     queue<pair<int,int>>q;
//     q.push({row,col});
//     int n=grid.size();
//     int m=grid[0].size();
//     while(!q.empty()){
//         int row=q.front().first;
//         int col=q.front().second;
//         q.pop();
//         //traverse the neibhour and mark them 
//         for(int delrow=-1;delrow<=1;delrow++){
//             for(int delcol=-1;delcol<=1;delcol++){
//                 int nrow=row+delrow;
//                 int ncol=col+delcol;
//                 if(vis[nrow][ncol]==0  && nrow>=0 && nrow<n 
//                  && ncol<m && ncol>=0 &&grid[nrow][ncol]='1' ){

//                     q.push({nrow,ncol});
//                     vis[nrow][ncol]=1;
//                 }
//             }
//         }

//     }


// }

// int noofisland(vector<vector<char>>&grid){
//     int n=grid.size();
//     int m=grid[0].size();
//     vector<vector<int>>vis(n,vector<int>(m,0));
//     int cnt=0;
//     for(int row=0;row<n;row++){
//         for(int col=0;col<m;col++){
//             if(!vis[row][col]&&grid[row][col]=='1'){
//                 bfs(row,col,vis,grid);
//                 cnt++;
//             }

//         }
//     }
//     return cnt;
// }

// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector <vector<char>> grid(n,vector<char>(m,'0'));
//     for(int i=0;i<m;i++){
//         int u,v;
//         cin>>u>>v;
//         grid[u][v]='1';
//         grid[v][u]='1';

//     }
//     int res=noofisland(grid);
//     cout<<"no of island"<<" " <<res<<endl;


// }