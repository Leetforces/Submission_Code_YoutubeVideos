#include <bits/stdc++.h>
using namespace std;


/// it's return type is Height 
int findDiameter(int src,int parent,vector<int> adj[],int& ans)
{
   
   
   int first_mx_height=0,second_mx_height=0;
   int count_of_child=0;
   
   //explore all child
   for(int child: adj[src]) 
   {
       if(child!=parent)
       {
           count_of_child++;
           
           int height= findDiameter(child,src,adj,ans);
           
           if(first_mx_height<height)
           {
               second_mx_height=first_mx_height;
               first_mx_height=height;
           }
           else if(second_mx_height< height)
           {
               second_mx_height=height;
           }
       }
   }
   
   // add 2 maximum height
   int tempAns=first_mx_height+second_mx_height;

   if(count_of_child>=2) tempAns+=2;
   else if(count_of_child==1) tempAns+=1;
   
   
   ans=max(ans,tempAns);
   
   // return height of current Node
   if(count_of_child>0 )
        return 1+first_mx_height;
   else 
        return 0;
}
int solve(vector<int> &parent_array)
{
    // find the size of node
    int n= parent_array.size();
    
    // make bidirectional adjacency list and find root
    vector<int> adj[n];
    int root;
    for(int i=0;i<n;i++)
    {
        if(parent_array[i]==-1) 
        {
            root= i;
            continue;
        }
        
        int u= i;
        int v= parent_array[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int ans=0;
    // find diameter of tree 
    findDiameter(root,-1,adj,ans);
    
    return ans;
}
