vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> level;
int k; //log2(n)+1 (no of bits in n)
void binary_lifting(int src, int par, int lev)
{
   up[src][0] = par;
   level[src] = lev;
   for (int i = 1; i <= k; i++)
   {
       if (up[src][i - 1] == -1)
           up[src][i] = -1;
       else
           up[src][i] = up[up[src][i - 1]][i - 1];
   }
   for (int child : adj[src])
   {
       if (par != child)
           binary_lifting(child, src, lev + 1);
   }
}
int query(int node, int jump)
{
   int temp = (1 << k);
   for (int i = k; i >= 0; i--)
   {
       if (jump >= temp)
       {
           jump -= (1 << i);
           node = up[node][i];
       }
       temp >>= 1;
   }
   return node;
}

