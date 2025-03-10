#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        vector<int> list;
        vector<int> potCeil;
        int total = 0;
        int _max = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            cin >> temp;
            _max = max(_max, temp);
            list.push_back(temp);
            total += temp;
        }

        for (int i = 1; i <= n; i++)
        {
            if (total % i == 0 && total / i >= _max)
                potCeil.push_back(total / i);
        }

        sort(potCeil.begin(), potCeil.end());
        potCeil.push_back(potCeil.back() + 1);
        int tracker = 0;
        int counter = 0;
        for (int i = 0; i < list.size(); i++)
        {
            if (counter < potCeil[tracker])
            {
                counter += list[i];
                continue;
            }
            else if (counter == potCeil[tracker])
            {
                counter = 0;
                counter += list[i];
                continue;
            }
            if (counter > potCeil[tracker])
            {
                if (counter > potCeil[tracker])
                    tracker++;
                counter = 0;
                i = -1;
            }
        }
        if (potCeil[tracker] != 0)
            cout << n - total / potCeil[tracker] << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}