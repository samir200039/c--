#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool dfs(int node,int col,vector<int>adj[],int color[]){
    color[node]=col;
    for(auto it:adj[node]){
        if(color[it]==-1){
            if(dfs(it,!col,adj,color)==false) return false;
        }
        else if(color[it]==color[node])return false;
    }
    return true;


}

bool isbarpartite(int v,vector<int>adj[]){
    int color[v];
    for(int i=0;i<v;i++){
        color[i]=-1;
    }
    for(int i=0;i<v;i++){
        if(color[i]==-1){
            if(dfs(i,0,adj,color)==false){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    
    return 0;
}