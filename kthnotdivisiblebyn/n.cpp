#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    int gap = a - 1;
    int group = b / gap;
    int remain = b % gap;
    if (remain == 0)
        cout << group * a + remain - 1 << endl;
    else
        cout << group * a + remain << endl;
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