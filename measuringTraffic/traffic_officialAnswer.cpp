#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
    int N, A[100], B[100];
    string T[100];

    ifstream fin("traffic.in");
    fin >> N;
    for (int i = 0; i < N; i++)
        fin >> T[i] >> A[i] >> B[i];

    ofstream fout("traffic.out");

    int a = -999999999, b = 999999999;
    for (int i = N - 1; i >= 0; i--)
    {
        if (T[i] == "none")
        {
            a = max(a, A[i]);
            b = min(b, B[i]);
        }
        if (T[i] == "off")
        {
            a += A[i];
            b += B[i];
        }
        if (T[i] == "on")
        {
            a -= B[i];
            b -= A[i];
            a = max(0, a);
        }
    }
    fout << a << " " << b << "\n";

    a = -999999999, b = 999999999;
    for (int i = 0; i < N; i++)
    {
        if (T[i] == "none")
        {
            a = max(a, A[i]);
            b = min(b, B[i]);
        }
        if (T[i] == "on")
        {
            a += A[i];
            b += B[i];
        }
        if (T[i] == "off")
        {
            a -= B[i];
            b -= A[i];
            a = max(0, a);
        }
    }
    fout << a << " " << b << "\n";

    return 0;
}