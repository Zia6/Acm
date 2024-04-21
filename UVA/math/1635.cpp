#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
int e[maxn], vis[maxn], prime[maxn], ee[maxn];
int cnt = 0;
vector<int> vv;
void euler()
{
    vis[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i]){
            prime[cnt++] = i;
            vis[i] = 1;
            // cout << i << ' ';
        }
        for (int j = 0; j < cnt && i * prime[j] < maxn; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void add_integer(int x, int d)
{
    for (int i = 0; i < cnt; i++)
    {
        while (x % prime[i] == 0)
        {
            e[i] += d;
            x /= prime[i];
        }
        if (x == 1)
            break;
    }
}
bool check()
{
    for (int i = 0; i < cnt; i++)
    {
        if (e[i] < ee[i])
        {
            return false;
        }
    }
    return true;
}
void solve(int n, int m)
{
    vv.clear();
    int ans = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        add_integer(n - i, 1);
        add_integer(i, -1);
        if (check())
        {
            ans++;
            vv.push_back(i + 1);
        }
    }
    cout << ans << '\n';
    for (auto it : vv)
    {
        cout << it << ' ';
    }
    cout << '\n';
}
int main()
{
    int n, m, mm;
    euler();
    while (cin >> n >> m)
    {
        cout << n << ' ' << m << '\n';
        for (int i = 0; i < cnt; i++)
        {
            // cout << 1 << '\n';
            while (m % prime[i] == 0)
            {
                ee[i] += 1;
                m /= prime[i];
            }
            if (m == 1)
                break;
        }
        if(m > 1){
            cout << 0 << '\n';
            cout << '\n';
            continue;
        }
        solve(n, mm);
    }
}