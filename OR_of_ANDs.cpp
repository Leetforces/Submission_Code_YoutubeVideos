/*
    https://www.youtube.com/watch?v=zYyPArQ3bgQ&t=2s
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589
#define MOD 1000000007
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0)
#define deb(x) cout << "[ " << #x << " = " << x << "] "

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    int bit[32] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        //increment set bit postion 
        for (int j = 0; j <= 31; j++)
            if ((1 << j) & arr[i])
                bit[j]++;
    }
    
    // calculating the current overall OR
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        if (bit[i])
            ans += (1 << i);
    }

    cout << ans << "\n";

    while (q--)
    {
        ans = 0;

        int pos, value;
        cin >> pos >> value;
        
        //removing previous value
        for (int j = 0; j <= 31; j++)
            if ((1 << j) & arr[pos - 1])
                bit[j]--;
        
        //adding bit of new value
        for (int j = 0; j <= 31; j++)
            if ((1 << j) & value)
                bit[j]++;
        
        //set the value in array position
        arr[pos - 1] = value;
        
        //calculate the answer 
        for (int i = 0; i < 32; i++)
            if (bit[i])
                ans += (1 << i);

        cout << ans << "\n";
    }
}

signed main()
{
    FAST_IO;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
