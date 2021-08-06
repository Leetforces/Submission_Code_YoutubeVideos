
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

