#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int N, K;
    cin >> N >> K;
    vector<int> seq(N);
    for (int i = 0; i < N; i++)
    {
        cin >> seq[i];
    }
    vector<vector<int>> dp(N, vector<int>(N, 1e9));
    for (int i = 0; i < N; i++)
    {
        dp[i][i] = 1;
    }
    for (int len = 2; len <= N; len++)
    {
        for (int i = 0; i + len - 1 < N; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            int L = j - i + 1;
            for (int p = 1; p <= L; p++)
            {
                if (L % p != 0)
                    continue;
                bool ok = true;
                for (int r = 0; r < L; r++)
                {
                    if (seq[i + r] != seq[i + (r % p)])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    dp[i][j] = min(dp[i][j], dp[i][i + p - 1]);
                    break;
                }
            }
        }
    }
    cout << (dp[0][N - 1] <= K ? "YES" : "NO") << "\n";
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
