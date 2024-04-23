#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
int e[maxn], vis[maxn], prime[maxn], ee[maxn];
int cnt = 0;
vector<int> vv;
void add_integer(int x, int d)
{
    for (int i = 0; i < cnt; i++)
    {
        while (x % prime[i] == 0)
        {
            ee[i] -= d;
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
        if (ee[i] > 0)
        {
            return false;
        }
    }
    return true;
}
void solve(int n)
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
    for (int i = 0; i < vv.size();i++)
    {
        cout << vv[i];
        cout << (i == vv.size() - 1 ? '\n' : ' ');
    }
    if(ans == 0)
        cout << '\n';
}
int main()
{
    int n, m, mm;
    while (cin >> n >> m)
    {
        cnt = 0;
        memset(ee, 0, sizeof(ee));
        int mm = floor(sqrt(m) + 0.5);
        // cout << n << ' ' << m << '\n';
        for (int i = 2; i <= mm; i++)
        {
            // cout << 1 << '\n';
            if (m % i == 0)
            {
                prime[cnt] = i;
                while (m % i == 0)
                {
                    ee[cnt]++;
                    m /= prime[cnt];
                }
                cnt++;
            }
        }
        if (m > 1)
        {
            prime[cnt] = m;
            ee[cnt++]++;
        }
        solve(n);
    }
}