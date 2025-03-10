#include <iostream>
#include <vector>
#include <fstream> // Include this for file handling
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
    for (int i = 0; i < _a - 1; i++) // finding adjacent sums
    {
        _sum.push_back(_x[i] + _x[i + 1]);
    }
    _x.insert(_x.begin() + SmallestAdjacent(_a, _sum) + 2, _x[SmallestAdjacent(_a, _sum)] + _x[SmallestAdjacent(_a, _sum) + 1]);
    _x.erase(_x.begin() + SmallestAdjacent(_a, _sum));
    _x.erase(_x.begin() + SmallestAdjacent(_a, _sum));
}

int main()
{
    // Open input file
    ifstream inputFile("sleep.in");
    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open input file 'sleep.in'." << endl;
        return 1;
    }

    // Open output file
    ofstream outputFile("sleep.out");
    if (!outputFile.is_open())
    {
        cerr << "Error: Could not open output file 'sleep.out'." << endl;
        return 1;
    }

    int times = 0;
    inputFile >> times; // Read number of test cases from input file
    vector<int> answers(times, 0);

    for (int j = 0; j < times; j++)
    {
        int a;
        inputFile >> a; // Read size of vector from input file
        vector<int> x(a);
        vector<int> sum;

        for (int i = 0; i < a; i++)
        {
            inputFile >> x[i]; // Read vector elements from input file
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
            for (int i = 0; i < x.size(); i++)
            {
                outputFile << x[i] << " ";
            }
            outputFile << endl;
        }

        answers[j] = answer;
    }

    // Write answers to output file
    for (int j = 0; j < times; j++)
    {
        // outputFile << answers[j] << endl;
    }

    // Close files
    inputFile.close();
    outputFile.close();

    return 0;
}