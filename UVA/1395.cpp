#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
struct edge
{
    int u, v, w;
    bool operator<(const edge &e) const
    {
        return w < e.w;
    }
};
int fa[maxn], vis[maxn];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y)
{
    int a = find(x), b = find(y);
    if (a != b)
    {
        fa[b] = a;
    }
}
vector<edge> e;
int main()
{
    int n, m, u, v, w, mr;
    int ans = 1e9 + 5;
    while (cin >> n && cin >> m && n)
    {
        ans = 1e9 + 5;
        e.clear();
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            e.push_back({u, v, w});
        }
        sort(e.begin(), e.end());
        int cnt = 0;
        for (int l = 0; l < m; l++)
        {
            cnt = 0, mr = -1e9 - 5;
            for (int i = 1; i <= n; i++)
            {
                fa[i] = i;
                vis[i] = 0;
            }
            for (int r = l; r < m; r++)
            {

                u = e[r].u, v = e[r].v;
                if (find(u) != find(v))
                {
                    merge(u, v);
                    cnt++;
                    mr = e[r].w;
                }
                if (cnt >= n - 1)
                {
                    ans = min(ans, mr - e[l].w);
                    break;
                }
            }
        }
        ans = ans == 1e9 + 5 ? -1 : ans;
        cout << ans << '\n';
    }
}