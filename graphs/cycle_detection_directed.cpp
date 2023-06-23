// cycle detection in directed cyclic graph using  dfs
#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<int>adj[],int vis[],int pathvis[]){
    vis[node]=1;
    pathvis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,pathvis)==true)return true;
        }
        else if(pathvis[it]) return true;
    }
    pathvis[node]=0;
    return false;

}

bool iscyclic(int v,vector<int>adj[]){
    int vis[v]={0};
    int pathvis[v]={0};

    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,pathvis)==true) return true;
        }
    }
    return false;
}

int main(){

}

 