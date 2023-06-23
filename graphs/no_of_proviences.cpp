//dfs implementation

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

 


void dfs(int node,vector<int> adjls[] ,int vis[]){
    vis[node]=1;
    for(auto it: adjls[node]){
        if(!vis[it]){
            dfs(it,adjls,vis);
        }
    }
}


int noofprov(vector<vector<int>>adj , int V){
    vector<int>adjls[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j]==1 && i!=j){
                adjls[i].push_back(j);
                adjls[j].push_back(i);
            }
        }
    }
    int vis[V]={0};
    int cnt=0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,adjls,vis);
        }
    }

}



int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n, vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int u,v;
            cin>>u>>v;
            adj[u][v]=1;
            adj[v][u]=1;
        }
    }

    
    return 0;
}