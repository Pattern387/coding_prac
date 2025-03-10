#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main()
{

    long long n;
    cin >> n;
    while (n--)
    {
        long long q;
        cin >> q;
        long long list[q];
        vector<long long> left, right;
        vector<long long> twocount(q, 0);
        long long twotracker = 0;
        for (long long i = 0; i < q; i++)
        {
            cin >> list[i];
            if (list[i] == 3)
            {
                right.push_back(i);
            }
            else if (list[i] == 1)
            {
                left.push_back(i);
            }
            else if (list[i] == 2)
            {
                twotracker++;
            }
            twocount[i] = twotracker;
        }
        long long ans = 0;
        for (long long i = 0; i < left.size(); i++)
        {
            for (long long j = 0; j < right.size(); j++)
            {
                if (right[j] > left[i])
                {
                    ans += (pow(2, twocount[right[j]] - twocount[left[i]]) - 1);
                }
                else
                    continue;
            }
        }
        int tAns = ans % MOD;
        cout << tAns << endl;
    }
    return 0;
}