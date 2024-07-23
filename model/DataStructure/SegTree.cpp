#include <iostream>
#include <cstring>
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
using ll = long long;
using ull = unsigned long long;

template <class T>
inline void read(T &x)
{
    x = 0;
    int f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    x *= f;
}

const int maxn = 1e5 + 5;
const int maxm = maxn << 6;

struct edge
{
    int to;
    int nex;
} e[maxn << 1];
int head[maxn], tot, f[maxn][20], dep[maxn];
int rt[maxn], sum[maxm], id[maxm], ls[maxm], rs[maxm], cnt = 0;
int n, m, u, v;
ll ans[maxn];
void push_up(int p)
{
    
    if (sum[ls[p]] >= sum[rs[p]])
    {
        id[p] = id[ls[p]];
        sum[p] = sum[ls[p]];
    }
    else
    {
        id[p] = id[rs[p]];
        sum[p] = sum[rs[p]];
    }
}

void update(int &p, int l, int r, int pos, ll x)
{
    if (!p)
        p = ++cnt;
    if (l == r)
    {
        sum[p] += x;
        id[p] = pos;
        return;
    }
    int mid = l + ((r - l) >> 1);
    if (pos <= mid)
    {
        update(ls[p], l, mid, pos, x);
    }
    else
        update(rs[p], mid + 1, r, pos, x);
    push_up(p);
}

int merge(int a, int b, int l, int r)
{
    if (!a || !b)
        return a + b;
    if (l == r)
    {
        sum[a] += sum[b];
        return a;
    }
    int mid = (l + r) >> 1;
    ls[a] = merge(ls[a], ls[b], l, mid);
    rs[a] = merge(rs[a], rs[b], mid + 1, r);
    push_up(a);
    return a;
}

void add_edge(int u, int v)
{
    e[cnt].to = v;
    e[cnt].nex = head[u];
    head[u] = cnt++;
}

void dfs(int u, int fa)
{
    f[u][0] = fa;
    dep[u] = dep[fa] + 1;
    for (int i = 1; i < 20; i++)
    {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (int i = head[u]; ~i; i = e[i].nex)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs(v, u);
    }
}

int lca(int a, int b)
{
    if (dep[a] < dep[b])
        std::swap(a, b);
    for (int i = 19; i >= 0; i--)
    {
        if (dep[f[a][i]] >= dep[b])
        {
            a = f[a][i];
        }
    }
    if (a == b)
        return a;
    for (int i = 19; i >= 0; i--)
    {
        if (f[a][i] != f[b][i])
        {
            a = f[a][i];
            b = f[b][i];
        }
    }
    return f[a][0];
}

void calc(int u, int fa)
{
    for (int i = head[u]; ~i; i = e[i].nex)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        calc(v, u);
        rt[u] = merge(rt[u], rt[v], 1, maxn);
    }
    ans[u] = id[rt[u]];
    if (sum[rt[u]] == 0)
        ans[u] = 0;
}

void solve()
{
    memset(head,-1,sizeof(head));
    read(n), read(m);
    for (int i = 0; i < n - 1; i++)
    {
        read(u), read(v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        read(x), read(y), read(z);
        int lc = lca(x, y);
        // std::cout << lc << '\n';
        update(rt[x], 1, maxn, z, 1);
        update(rt[y], 1, maxn, z, 1);
        update(rt[lc], 1, maxn, z, -1);
        update(rt[f[lc][0]], 1, maxn, z, -1);
    }
    calc(1,0);
    for(int i = 1;i <= n;i++){
        std::cout << ans[i] << '\n';
    }
}

int main()
{
    solve();
    return 0;
}