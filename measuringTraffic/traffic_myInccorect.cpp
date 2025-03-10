#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    ifstream inputFile("traffic.in");
    ofstream outputFile("traffic.out");
    int a = 0;
    inputFile >> a;
    vector<string> type(a);
    vector<int> under(a);
    vector<int> over(a);
    for (int i = 0; i <= a - 1; i++)
    {
        inputFile >> type[i] >> under[i] >> over[i];
    }
    type.push_back("end");
    int firstSegment = 0;
    int changesHigh = 0, changesLow = 0;
    while (type[firstSegment] == "on" || type[firstSegment] == "off")
    {
        if (type[firstSegment] == "on")
        {
            changesLow += over[firstSegment];
            changesHigh += under[firstSegment];
        }
        if (type[firstSegment] == "off")
        {
            changesLow -= under[firstSegment];
            changesHigh -= over[firstSegment];
        }
        firstSegment++;
    }

    int high = over[firstSegment], low = under[firstSegment];
    while (type[firstSegment] == "none" || type[firstSegment] == "end")
    {
        high = min(high, over[firstSegment]);
        low = max(low, under[firstSegment]);
        firstSegment++;
    }

    high -= changesHigh;
    low -= changesLow;
    if (low < 0)
    {
        outputFile << 0 << " ";
    }
    else
    {
        outputFile << low << " ";
    }
    if (high < 0)
    {
        outputFile << 0 << endl;
    }
    else
    {
        outputFile << high << endl;
    }

    // done with entre
    int lastSegment = 0;
    lastSegment = a - 1;
    changesHigh = 0, changesLow = 0;
    while (type[lastSegment] == "on" || type[lastSegment] == "off")
    {
        if (type[lastSegment] == "on")
        {
            changesLow += over[lastSegment];
            changesHigh += under[lastSegment];
        }
        if (type[lastSegment] == "off")
        {
            changesLow -= under[lastSegment];
            changesHigh -= over[lastSegment];
        }
        lastSegment--;
    }
    high = over[lastSegment], low = under[lastSegment];
    while (type[lastSegment] == "none" || type[lastSegment] == "end")
    {
        high = min(high, over[lastSegment]);
        low = max(low, under[lastSegment]);
        lastSegment--;
    }

    high += changesLow;
    low += changesHigh;
    if (low < 0)
    {
        outputFile << 0 << " ";
    }
    else
    {
        outputFile << low << " ";
    }
    if (high < 0)
    {
        outputFile << 0 << endl;
    }
    else
    {
        outputFile << high << endl;
    }

    return 0;
}