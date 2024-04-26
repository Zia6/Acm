#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <sstream>
using namespace std;
const int maxn = 105;
const int inf = 1e7 + 5;
int d[maxn][maxn], n, m, q, T = 0;
void init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = inf;
        }
        d[i][i] = 0;
    }
}
void solve()
{
    init();
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        cin >> d[u][v];
        d[v][u] = d[u][v];
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(d[i][k] != inf && d[k][j] != inf)
                d[i][j] = min(d[i][j], max(d[i][k],d[k][j]));
            }
        }
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (d[u][v] != inf)
            cout << d[u][v] << '\n';
        else
            cout << "no path" << '\n';
    }
}
int main()
{
    while (cin >> n >> m >> q && n && m && q)
    {
        cout << "Case #" << ++T << '\n';
        solve();
        cout << '\n';
    }
    return 0;
}