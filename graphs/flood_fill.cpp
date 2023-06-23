#include<iostream>
#include<vector>
using namespace std;


void dfs(int row,int col,vector<vector<int>>&img,vector<vector<int>>&ans,int newcolor,int inicolor,int delrow[],int delcol[]){
    ans[row][col]=newcolor;
    int n=img.size();
    int m=img[0].size();
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && ncol>=0 && nrow >n  &&  ncol>m && img[nrow][ncol]==inicolor && ans[nrow][ncol]==newcolor){
            dfs(nrow,ncol,img,ans,newcolor,inicolor,delrow,delcol);
        }

    }
    
}
vector<vector<int>>floodfill(int sr,int sc,vector<vector<int>>&img ,int newcolor){
    int  inicolor=img[sr][sc];
    vector<vector<int>>ans=img;
    int delrow[]={-1,0,+1,0};
    int delcol[]={0,+1,0,-1};
    dfs(sr,sc,img,ans,newcolor,inicolor,delrow,delcol);

}

int main()
{
    
    return 0;
}

//using bfs

/*
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> floodFill(int sr, int sc, vector<vector<int>>& img, int newColor) {
    int n = img.size();
    int m = img[0].size();
    int inicolor = img[sr][sc];
    vector<vector<int>> ans = img;

    if (inicolor == newColor)
        return ans;

    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    queue<pair<int, int>> q;
    q.push({sr, sc});
    ans[sr][sc] = newColor;

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] == inicolor) {
                ans[nrow][ncol] = newColor;
                q.push({nrow, ncol});
            }
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> img = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};   
    // 1 1 1
    // 1 1 0
    // 1 0 1
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> res = floodFill(sr, sc, img, newColor);

    cout << "Original Image:" << endl;
    for (const auto& row : img) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "Flood-Filled Image:" << endl;
    for(int i=0;i<res.size();i++){
       for(int j=0;j<res[0].size();j++){
           cout<<res[i][j]<< " ";
       }
        cout << endl;
   }
    

    return 0;
}


Image:
0 1 0 
1 0 1 
0 1 1 
Ans:
0 1 0 
1 0 2 
0 1 1



*/