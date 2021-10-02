#include <bits/stdc++.h>
using namespace std;


bool isPath(int src, int& dest,vector<int>adj[], vector<bool>& visited){
    // make it visited
    visited[src]=true;
    
    for(int child: adj[src]){
        // if we reach our destination
        if(child==dest) return true;
        
        // if child is unvisited and any path from there
        if(visited[child]==false && isPath(child,dest,adj,visited)){
            return true;
        }
    }
    // there is no any path to reach destination
    return false;
}
int solve(int n, vector<vector<int> > &edge) {
    
    //make adjacency list of directed graph
    vector<int> adj[n+1];
    for(int i=0;i<edge.size();i++){
        int u= edge[i][0];
        int v= edge[i][1];
        adj[u].push_back(v);
    }
    
    // initially all nodes --> unvisited
    vector<bool> visited(n+1,false);
    
    // is any path
    return isPath(1,n,adj,visited);
    
}
