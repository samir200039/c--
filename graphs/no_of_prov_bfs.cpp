#include<bits/stdc++.h>
using namespace std;



int noofprovinces(int V,vector<vector<int>>adj){
    vector<int>ls[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j]==1 && i!=j){
                ls[i].push_back(j);
                ls[j].push_back(i);
            }
        }
    }
    int vis[V]={0};
    int cnt=0;
    queue<int>q;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            vis[i]=1;
            q.push(i);
            while (!q.empty())
            {
                int node=q.front();
                q.pop();
            for(auto it:ls[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }

            }
            
        }
    }

} 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    int res=noofprovinces(n,adj);
    cout<<"no of provimces"<<res<<endl;

    return 0;
}