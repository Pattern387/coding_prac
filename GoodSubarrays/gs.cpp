#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int q;
        cin >> q;
        int ceil = 0;
        vector<int> sub(q, 0);
        vector<int> letter(q, 0);
        vector<int> tracker(1e5, 0);
        sub[0] = 0;
        string temp;
        cin >> temp;
        for (int i = 1; i < q; i++)
        {
            int tempI = temp[i] - '0';
            sub[i] = tempI + sub[i - 1];
            letter[i] = sub[i] - 1;
            ceil = max(ceil, letter[i]);
            tracker[letter[i]]++;
        }
        int ans = 0;

        for (int i = 0; i <= ceil; i++)
        {
            if (tracker[i] > 1)
                ans += tracker[i];
        }
        cout << (ans - 1) / 2 << endl;
    }
}