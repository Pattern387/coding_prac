#include <bits/stdc++.h>

using namespace std;

void solve()
{
    bool ans = true;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    a[0] = min(a[0], b[0] - a[0]);
    for (int i = 1; i < n; i++)
    {
        int low = min(a[i], b[0] - a[i]);
        int high = max(a[i], b[0] - a[i]);
        if (low >= a[i - 1])
        {
            a[i] = low;
        }
        else
        {
            a[i] = high;
        }

        if (a[i] < a[i - 1])
        {
            ans = false;
        }
    }

    if (ans)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}