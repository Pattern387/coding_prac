#include <bits/stdc++.h>
using namespace std;

#define fo(i, l, r) for (int i = (l); i <= (r); i++)
#define of(i, l, r) for (int i = (l); i >= (r); i--)

static const int MAXN = 1000005;
int N, x, leafCount;
int par[MAXN], sz[MAXN], dep[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int p)
{
    par[u] = p;
    for (auto &v : adj[u])
    {
        if (v == p)
            continue;
        dep[v] = dep[u] + 1;
        sz[u]++;
        dfs(v, u);
    }
    if (!sz[u])
        leafCount++;
}

void solve()
{
    cin >> N;
    fo(u, 1, N)
    {
        cin >> x;
        adj[u].push_back(x);
        adj[x].push_back(u);
    }
    dfs(0, -1);
    while (leafCount--)
    {
        cin >> x;
        while (x && !sz[x])
        {
            x = par[x];
            sz[x]--;
        }
        int ans = dep[x];
        if (sz[x])
            ans++;
        cout << ans << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
