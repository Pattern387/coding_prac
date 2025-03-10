#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> list(n);
        vector<int> key(m);
        for (int i = 0; i < n; i++)
            cin >> list[i];
        for (int i = 0; i < m; i++)
            cin >> key[i];

        sort(key.begin(), key.end());
        list[0] = min(key[0] - list[0], list[0]);
        bool ans = true;
        for (int i = 1; i < n; i++)
        {
            if (max(key[0] - list[i], list[i]) >= list[i - 1])
            {
                if (min(key[0] - list[i], list[i]) >= list[i - 1])
                {
                    list[i] = min(key[0] - list[i], list[i]);
                }
            }
            else
            {
                ans = false;
                break;
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}