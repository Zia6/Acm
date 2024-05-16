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
const int maxn = 1e3 + 5;
vector<long long> ans;
struct point
{
    int x, y;
    int operator-(const point &p)
    {
        return pow((x - p.x), 2) + pow((y - p.y), 2);
    }// 返回两个点的距离
} p[maxn];
struct edge
{
    int u, v, w;
    bool operator<(const edge &e)
    {
        return w < e.w;
    }
} e[maxn * maxn];
int fa[maxn], mon[10];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y)
{
    int t1 = find(x), t2 = find(y);
    fa[t1] = t2;
}
void solve()
{
    long long min_ans = 0xfffffffffffffff;
    vector<edge> v, vv;
    vector<int> net[10];
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int cc = 0;
        cin >> cc >> mon[i];
        for (int j = 0; j < cc; j++)
        {
            int t;
            cin >> t;
            net[i].push_back(t);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        cin >> p[i].x >> p[i].y;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            e[cnt].u = i;
            e[cnt].v = j;
            e[cnt++].w = p[i] - p[j];
        }
    }
    sort(e, e + cnt);
    for (int i = 0; i < cnt; i++)
    {
        if (find(e[i].u) != find(e[i].v))
        {
            merge(e[i].u, e[i].v);
            v.push_back(e[i]);
        }
        if (v.size() == n - 1)
        {
            break;
        }
    }
    for (int tt = 0; tt < (1 << m); tt++)
    {
        vv = v;
        long long tem = 0;
        for (int i = 0; i < m; i++)
        {
            if (!((tt >> i) & 1))
                continue;
            tem += mon[i];
            for (int j = 0; j < net[i].size(); j++)
            {
                for (int k = j + 1; k < net[i].size(); k++)
                {
                    vv.push_back({net[i][j], net[i][k], 0});
                }
            }
        }
        sort(vv.begin(), vv.end());
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
        }
        int cnt2 = 0;
        for (int i = 0; i < vv.size(); i++)
        {
            if (find(vv[i].u) != find(vv[i].v))
            {
                merge(vv[i].u, vv[i].v);
                tem += vv[i].w;
                cnt2++;
            }
            if (cnt2 == n - 1)
                break;
        }
        if (tem < min_ans)
            min_ans = tem;
    }
    ans.push_back(min_ans);
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    for(int i = 0;i < ans.size();i++){
        cout << ans[i] << '\n';
        if(i != ans.size() - 1) cout << '\n';
    }
    return 0;
}