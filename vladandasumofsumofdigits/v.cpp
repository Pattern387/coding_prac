#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> l(200001, "0");
    vector<int> o(200001, 0);
    for (int i = 1; i <= 9; i++)
    {
        o[i] = i;
    }
    for (int i = 10; i <= 200000; i++)
    {
        string temps = to_string(i);
        char firstChar = temps[0];
        temps = temps.substr(1);
        int tempn = stoi(temps);
        o[i] = o[tempn] + firstChar - '0';
    }

    for (int i = 1; i <= 9; i++)
    {
        int temp = stoi(l[i - 1]);
        l[i] = to_string(i + temp);
    }
    for (int i = 10; i <= 200000; i++)
    {
        int temp = stoi(l[i - 1]);
        l[i] = to_string(o[i] + temp);
    }
    int n;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        cout << l[num] << endl;
    }
    return 0;
}