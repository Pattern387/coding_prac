#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int Find(int a, int b, vector<vector<int>> &arr, int rounds, int cow)
{
    int quota = 0;
    for (int l = 1; l < rounds; l++)
    {
        for (int d = 0; d < cow; d++)
        {
            if (arr[l][d] == a) // found 4
            {
                for (int k = d; k < cow; k++)
                {
                    if (arr[l][k] == b) // found 1
                    {
                        quota++;
                    }
                }
            }
        }
    }
    if (quota == rounds - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    ifstream infile("gymnastics.in");
    ofstream outfile("gymnastics.out");

    int k, n;
    infile >> k >> n;
    int answer = 0;

    vector<vector<int>> matrix(k, vector<int>(n));

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            infile >> matrix[i][j];
        }
    }

    // Process the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            answer += Find(matrix[0][i], matrix[0][j], matrix, k, n);
        }
    }

    outfile << answer;
    // Close the files

    infile.close();
    outfile.close();

    return 0;
}