#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int end = (n - 27) / 2;
    if (n < 27 && n % 2 == 1)
    {
        cout << -1;
    }
    else if (n % 2 == 0)
    {
        for (int i = 1; i <= n / 2; i++)
        {
            cout << i << " " << i << " ";
        }
    }
    else if (n >= 27 && n % 2 == 1)
    {
        cout << "1 3 3 4 4 5 5 6 6 1 2 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 2 ";
        for (int i = 0; i < end; i++)
        {
            cout << i + 14 << " " << i + 14 << " ";
        }
    }

    cout << endl;
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