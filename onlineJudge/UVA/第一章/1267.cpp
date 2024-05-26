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
#include <cstring>
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
int fa[maxn], vis[maxn];
std::vector<int> son[maxn];
std::vector<int> v[maxn];
int md = 0, k = 0;
void dfs(int x, int f, int d)
{
    fa[x] = f;
    if (son[x].size() == 1 && d > k)
        v[d].push_back(x);
    for (int i = 0; i < son[x].size(); i++)
    {
        if (son[x][i] == f)
            continue;
        dfs(son[x][i], x, d + 1);
    }
}

void dfs2(int x, int f, int d)
{
    if(d > k) return;
    vis[x] = 1;
    for (int i = 0; i < son[x].size(); i++)
    {
        if (son[x][i] == f)
            continue;
        dfs2(son[x][i], x, d + 1);
    }
}
void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        son[i].clear();
        vis[i] = 0;
        v[i].clear();
    }
}
void solve()
{
    int n, root;
    std::cin >> n >> root >> k;
    init(n);
    int ans = 0;
    for(int i = 0;i < n - 1;i++){
        int a,b;
        std:: cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    dfs(root, -1, 0);
    for(int i = n - 1;i > k;i--){
        for(int j = 0;j < v[i].size();j++){
            int u = v[i][j];
            if(vis[u]) continue;
            for(int w = 0;w < k;w++){
                u = fa[u];
            }
            ans++;
            dfs2(u,-1,0);
        }
    }
    std:: cout << ans << '\n';
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}