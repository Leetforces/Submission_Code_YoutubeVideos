#include <bits/stdc++.h>
using namespace std;




void dfs(int src,int parent,int goodNodes,vector<int>& typeOfNode,vector<int> adj[],int& mxGoodNodes,int& ans)
{ 
       // increment if good Nodes
       if(typeOfNode[src-1]==1) goodNodes++;
       // if good nodes exceeds the limit
       if(goodNodes> mxGoodNodes) return;
       
       
       int count_of_child=0;
       
       // explore it child
       for(int child: adj[src])
       {
           
           if(child!=parent)
           {
               count_of_child++;
               // call the dfs for its child
               dfs(child,src,goodNodes,typeOfNode,adj,mxGoodNodes,ans);
           }
       }
       
       // if we reach at leaf node
       if(count_of_child==0)
       {
           ans++;
       }
}

int solve(vector<int> &typeOfNode, vector<vector<int> > &edges, int mxGoodNodes) 
{
    // find the size of nodes
    int n= typeOfNode.size();
    
    // make bidirectional adjacency list
    vector<int> adj[n+1];
    for(int i=0;i<edges.size();i++)
    {
        int u= edges[i][0];
        int v= edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    int ans=0;

    // call dfs to get answer
    dfs(1,-1,0,typeOfNode,adj,mxGoodNodes,ans);
    
    return ans;
}










/*
  Time Complexity  : O(N+E)
  Space Complexity : O(N+E)

*/