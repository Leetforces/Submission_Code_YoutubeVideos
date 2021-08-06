const int N=300001;
int fact[N];
int power(int x, int a)
{
     int ans = 1;
     x = x % MOD;
     while (a > 0)
     {
         if (a & 1)
             ans = (ans * x) % MOD;
         a >>= 1;
         x = (x * x) % MOD;
     }
     return ans;
}
void pre()
{
     fact[0]=1;
     for(int i=1;i<=N;i++)
     fact[i]=(fact[i-1]*i)%MOD;
}
int ncr(int n,int r)
{
     if(n<r) 
        return 0;
     if(r == 0)
        return 1;
     return (fact[n] * power((fact[r]*fact[n-r])%MOD, MOD-2)% MOD) % MOD;
}

