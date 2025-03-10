#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int distanceInOneTrip(int a, int b)
{
    if (a > b)
    {
        return a - b;
    }
    else
    {
        return b - a;
    }
}

int main()
{
    ifstream inputFile("lostcow.in");
    ofstream outputFile("lostcow.out");

    if (!inputFile || !outputFile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int x, y;
    inputFile >> x >> y;

    int mDir = 1, mDisfrmO = 1, mTtlDis = 0, lst_pos = x;
    while (1)
    {
        int current_pos = x + (mDisfrmO * mDir);

        if (mDir == 1 && current_pos >= y && y > x)
        {
            mTtlDis += distanceInOneTrip(y, lst_pos);
            break;
        }
        else if (mDir == -1 && current_pos <= y && y < x)
        {
            mTtlDis += distanceInOneTrip(y, lst_pos);
            break;
        }
        else
        {
            mTtlDis += distanceInOneTrip(current_pos, lst_pos);
            mDir *= -1;
            mDisfrmO *= 2;
        }

        lst_pos = current_pos;
    }

    outputFile << mTtlDis;

    inputFile.close();
    outputFile.close();

    return 0;
}
