//store graph using --- matrices

// how to store graph data struture using o(2E) time compelxity  -- linked list
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;   // no of edges and nodes 
    vector<int>adj[n+1];
    // for undirected graph a--b 
    for(int i=0;i<m;i++){   //har ek edge ke liye uska two point le rhe hai like a---b 
        int u,v;
        cin>>u>>v;  
        adj[u].push_back(v);   // in case of directed graph   u-->>v   
                                //we will not reqiire  ------>>>> adj[v].push_back(u);
        adj[v].push_back(u);   
    }


    return 0;
}