#include <bits/stdc++.h>

using namespace std;

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; ++i)
   {
      cin >> a[i];
   }
   int best = 0;
   int l = 0, r = 0;
   for (int i = 0; i < n; i++)
   {
      int b = 0, s = 0;
      for (int j = i + 1; j < n; j++)
      {
         if (a[j] > a[i])
            b++;
         if (a[j] < a[i])
            s++;
         if (best > b - s)
         {
            best = b - s;
            l = i;
            r = j;
         }
      }
   }
   cout << l + 1 << ' ' << r + 1 << '\n';
}

int main()
{
   int tt = 1;
   cin >> tt;
   while (tt-- > 0)
   {
      solve();
   }
   return 0;
}