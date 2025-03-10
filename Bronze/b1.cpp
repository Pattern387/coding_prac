#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void solve()
{
    int N, U;
    cin >> N >> U;
    vector<string> canvas(N);
    for (int i = 0; i < N; i++)
    {
        cin >> canvas[i];
    }
    int M = N / 2;
    int numOrbits = M * M;
    vector<int> orbitCount(numOrbits, 0);
    auto getOrbitIndex = [&](int r, int c) -> int
    {
        int r0 = (r <= M ? r : N + 1 - r);
        int c0 = (c > M ? c : N + 1 - c);
        return (r0 - 1) * M + (c0 - (M + 1));
    };
    long long totalCost = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int idx = getOrbitIndex(i, j);
            if (canvas[i - 1][j - 1] == '#')
                orbitCount[idx]++;
        }
    }
    for (int k = 0; k < numOrbits; k++)
    {
        if (orbitCount[k] > 2)
            totalCost += 4 - orbitCount[k];
        else
            totalCost += orbitCount[k];
    }
    cout << totalCost << "\n";
    for (int u = 0; u < U; u++)
    {
        int r, c;
        cin >> r >> c;
        int idx = getOrbitIndex(r, c);
        int oldCost = min(orbitCount[idx], 4 - orbitCount[idx]);
        if (canvas[r - 1][c - 1] == '#')
        {
            canvas[r - 1][c - 1] = '.';
            orbitCount[idx]--;
        }
        else
        {
            canvas[r - 1][c - 1] = '#';
            orbitCount[idx]++;
        }
        int newCost = min(orbitCount[idx], 4 - orbitCount[idx]);
        totalCost = totalCost - oldCost + newCost;
        cout << totalCost << "\n";
    }
}

int main()
{

    solve();
    return 0;
}
