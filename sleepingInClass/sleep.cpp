#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int SmallestAdjacent(int size, vector<int> _sum)
{
    int pos = 0;
    int temp = 10000000;
    for (int i = 0; i < size - 1; i++)
    {
        if (temp > _sum[i])
        {
            temp = _sum[i];
            pos = i;
        }
    }
    return pos;
}
void Operation(int _a, vector<int> &_x, vector<int> &_sum)
{
    for (int i = 0; i < _a - 1; i++) // finding a adjacent sums
    {
        _sum.push_back(_x[i] + _x[i + 1]);
    }
    _x.insert(_x.begin() + SmallestAdjacent(_a, _sum) + 2, _x[SmallestAdjacent(_a, _sum)] + _x[SmallestAdjacent(_a, _sum) + 1]);
    _x.erase(_x.begin() + SmallestAdjacent(_a, _sum));
    _x.erase(_x.begin() + SmallestAdjacent(_a, _sum));

    //_sum.clear();
}

int main()
{
    int times = 0;
    cin >> times;
    vector<int> answers(times, 0);
    for (int j = 0; j < times; j++)
    {
        int a;
        cin >> a;
        vector<int> x(a);
        vector<int> sum;
        for (int i = 0; i < a; i++)
        {
            cin >> x[i];
        }
        int answer = 0;
        while (x.size() != 1)
        {

            int count = 0;
            for (int i = 0; i < x.size() - 1; i++)
            {
                if (x[i] == x[i + 1])
                {
                    count++;
                }
            }
            if (count == x.size() - 1)
            {
                break;
            }

            Operation(a, x, sum);
            a--;
            answer++;
            sum.clear();
        }

        answers[j] = answer;
    }

    for (int j = 0; j < times; j++)
    {
        cout << answers[j] << endl;
    }
}