#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
    return x;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> dp(4, 0);
        dp[0] = 1;
        while (n--)
        {
            int x;
            cin >> x;
            if (x == 2)
                dp[x] = add(dp[x], dp[x]);
            dp[x] = add(dp[x], dp[x - 1]);
        }

                cout << dp[3] << '\n';
    }
}