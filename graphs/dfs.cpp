#include<iostream>
#include<vector>

using namespace std;

void dfsutil(int node , vector<int>adj[], int vis[],vector<int>&ls){
    vis[node]=1;
    ls.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            dfsutil(it,adj,vis,ls);
        }
    }
}
vector<int>dfs(vector<int>adj[] ,int n){
    int vis[n]={0};
    vis[0]=1;
    vector<int>st;
    int start=0;
    dfsutil(0,adj,vis,st);

    return st ;

}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);


    }
    vector<int>res=dfs(adj,n);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";

    }
    cout<<endl;
    return 0;
}