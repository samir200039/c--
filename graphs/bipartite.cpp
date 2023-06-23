// pprogram to write a bipartirt graph in bfs  

#include<bits/stdc++.h>
using namespace std;


bool  isbipartite(int v , vector<int>adj[],int color[]){
    
    queue<int>q;
    q.push(0);
    // int color[v];
    // for(int i=0;i<v;i++)color[i]=-1;
    color[0]=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                q.push(it);

            }
            else if(color[it]==color[node]){
                return false;
            }
        }
    }
    return true;
        
}

bool check(int v,vector<int>adj [] ){
    int color[v];
    for(int i =0;i<v;i++) color[i]=-1;
    for(int i=0;i<v;i++){
        if(color[i]==-1){
            if(isbipartite(i,adj,color)==false){
                return false;
            }
        }
    }
    return true;
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

       
    }

    


    check(n,adj);

    
    return 0;
}



































