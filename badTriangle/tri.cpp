#include <bits/stdc++.h>

using namespace std;
const int inf = 1000000000 + 1;

void solve()
{
    int q;
    cin >> q;
    int big = 0, sml = inf, sec = inf;
    int bigi, smli, seci;
    vector<int> l(q);
    vector<int> dum(q);
    int fitssmlidx = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> l[i];
        if (big < l[i])
        {
            big = l[i];
            bigi = i;
        }
        if (sml > l[i])
        {
            sml = l[i];
            smli = i;
        }
        else if (sec > l[i])
        {
            sec = l[i];
            seci = i;
        }
    }
    int arr[] = {bigi, smli, seci};
    sort(arr, arr + 3);
    if (big >= sml + sec)
    {
        cout << arr[0] + 1 << " " << arr[1] + 1 << " " << arr[2] + 1;
    }
    else
    {
        cout << -1;
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