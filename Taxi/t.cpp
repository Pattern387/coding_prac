#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> list(n);
    vector<int> pl(5, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
        pl[list[i]]++;
    }
    ans += pl[4];
    pl[4] = 0;

    int lid = min(pl[1], pl[3]);
    ans += lid;
    pl[1] -= lid;
    pl[3] -= lid;
    if (pl[3] != 0)
        ans += pl[3];
    pl[3] = 0;

    lid = min(pl[2], pl[1] / 2);
    ans += lid;
    pl[2] -= lid;
    pl[1] -= lid * 2;
    if (pl[2] != 0 && pl[1] != 0)
    {
        pl[1]--;
        pl[2]--;
        ans++;
    }
    if (pl[2] != 0 && pl[1] == 0)
    {
        ans += ceil(double(pl[2]) / 2);
    }

    ans += ceil(double(pl[1]) / 4);
    cout << ans;
    return 0;
}