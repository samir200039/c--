#include <bits/stdc++.h>
using namespace std;


//implementing this code using for loop (Brute force )
string twoSum(int n, vector<int> &arr, int target) {
    for(int i=0;i<n;i++){
       for (int j = i+1; j<n; i++){
        if(arr[i]+arr[j]==target){
            return "yes";
        }
       } 
        
    }
    return "no";
}

string twosum(int n,vector<int>&arr,int target){
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int num=arr[i];
        int remele=target-num;
        if(mp.find(remele)!=mp.end()){   
            return{i,mp[remele]};
        }
        int 
    }
    return {-1,-1};
}