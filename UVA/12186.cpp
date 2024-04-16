#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> son[maxn];
int n, t, u, v;
int dp(int u)
{
    vector<int> d;
    int ans = 0, l = son[u].size();
    if (l == 0)
        return 1;
    for (int i = 0; i < l; i++)
    {
        d.push_back(dp(son[u][i]));
    }
    sort(d.begin(), d.end());

    int c = (l * t - 1) / 100 + 1;
    for (int i = 0; i < c; i++)
    {
        ans += d[i];
    }
    return ans;
}
int main()
{

    while (cin >> n >> t && n && t)
    {
        for (int i = 0; i <= n; i++)
        {
            son[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> u;
            son[u].push_back(i);
        }
        cout << dp(0) << '\n';
    }
}