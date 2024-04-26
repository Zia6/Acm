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
map<string, int> mp;
const int maxn = 30;
int d[maxn][maxn], n, m, cnt, fa[maxn], T = 0;
string name[maxn];
const int inf = -1;
void init()
{
    cnt = 0;
    mp.clear();
    for (int i = 0; i < n; i++)
    {
        fa[i] = i;
        d[i][i] = 1;
        for (int j = 0; j < n; j++)
        {
            d[i][j] = 0;
        }
    }
}
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int t1 = find(x), t2 = find(y);
    fa[t1] = t2;
}
void solve()
{
    init();
    string s1, s2;
    for (int i = 0; i < m; i++)
    {
        cin >> s1 >> s2;
        if (!mp.count(s1))
        {
            mp.insert({s1, cnt});
            name[cnt++] = s1;
        }
        if (!mp.count(s2))
        {
            mp.insert({s2, cnt});
            name[cnt++] = s2;
        }
        int u = mp[s1], v = mp[s2];
        d[u][v] = 1;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] |= (d[i][k] & d[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i][j] && d[j][i])
            {
                merge(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (find(i) == i)
        {
            vector<int> ans;
            for (int j = 0; j < n; j++)
            {
                if (find(j) == i)
                {
                    ans.push_back(j);
                }
            }
            for (int j = 0; j < ans.size(); j++)
            {
                cout << name[ans[j]];
                cout << (j == ans.size() - 1 ? "\n" : ", ");
            }
        }
    }
}
int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m && n && m)
    {
        if (T)
            cout << '\n';
        cout << "Calling circles for data set " << ++T << ":\n";
        solve();
    }
    return 0;
}