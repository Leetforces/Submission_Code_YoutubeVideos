template <typename dataType>
vector<pair<dataType, dataType>> primeDivisor(dataType n)
{
    vector<pair<dataType, dataType>> ans;
    if (n <= 3)
    ans.push_back({n, 1});
    else
    {
        for (dataType i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                    dataType count = 0;
                    while (n % i == 0)
                    {
                        count++;
                        n /= i;
                    }
                    ans.push_back({i, count});
           }
        }
    if (n > 1)
        ans.push_back({n, 1});
    }
    return ans;
}