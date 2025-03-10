#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; i++)
        cin >> list[i];
    int a[2];
    a[0] = 0;
    a[1] = 0;
    int left = 0, right = n - 1;
    int rounds = 0;
    while (left <= right)
    {
        if (list[left] > list[right])
        {
            a[rounds % 2] += list[left];
            left++;
            rounds++;
        }
        else
        {
            a[rounds % 2] += list[right];
            right--;
            rounds++;
        }
    }

    cout << a[0] << " " << a[1];

    return 0;
}
