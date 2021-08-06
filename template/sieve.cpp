const int N=100000;
vector<bool> isPrime(N+1,1);
void sieve()
{
    isPrime[0] = 0;
    if (N >= 1)
        isPrime[1] = 0;
    for (int i = 2; i * i <= N; i++)
    {
        if(isPrime[i])
        for (int j = i * i; j <= N; j += i)
        isPrime[j] = 0;
    }
}

