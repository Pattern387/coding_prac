#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream> // Include this for file handling
using namespace std;
int main()
{
    ifstream infile("pails.in");   // Open the input file
    ofstream outfile("pails.out"); // Open the output file
    int a, b, c;
    infile >> a >> b >> c;
    int baseAmount = 0;
    int maxA = 0;
    do
    {
        int count = baseAmount;
        for (int i = 0; i <= c / a - 1; i++)
        {
            if (count + a <= c)
            {
                count = count + a;
            }
        }
        maxA = max(maxA, count);
        baseAmount += b;
    } while (baseAmount < c);

    outfile << maxA;

    return 0;
}
