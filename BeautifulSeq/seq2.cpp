#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> l(n);
    vector<int> ts(n);
    vector<int> to;
    vector<int> tt;
    int tcount = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
        if (l[i] == 2)
        {
            tcount++;
        }
        ts[i] = tcount;

        if (l[i] == 3)
        {
            tt.push_back(i);
        }
        if (l[i] == 1)
        {
            to.push_back(i);
        }
    }

    for (int i = 0; i < to.size(); i++)
    {
        for (int j = 0; j < tt.size(); j++)
        {
            if (to[i] < tt[j])
            {
                int numts = ts[tt[j]] - ts[to[i]];
                ans = (ans + ((1LL << numts) - 1)) % 998244353;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    for (int i = 0; i <= 200000; i++)
    {
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}