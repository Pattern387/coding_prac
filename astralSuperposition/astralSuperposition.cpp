#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x, y, count = 0;
    cin >> n >> x >> y;

    vector<vector<char>> matrix(n, vector<char>(n));

    for (int i = 0; i < n; ++i) // input all
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 'B' && matrix[i - x][j - y] == 'W') // find error
            {
                //=-1
            }
            if (matrix[i][j] == 'B' && matrix[i - x][j - y] != 'W')
            {
                //+1
                matrix[i][j] = 'G';
                if (matrix[i - x][j - y] == 'G')
                {
                    matrix[i - x][j - y] = 'W';
                }
                if (matrix[i - x][j - y] == 'B')
                {
                    matrix[i - x][j - y] = 'G';
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) // input all
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matrix[i][j];
        }
    }

    return 0;
}
