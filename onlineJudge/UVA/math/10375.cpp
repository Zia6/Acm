#include <iostream>
#include <iomanip>
using namespace std;
const int maxn = 1e4 + 5;
int prime[maxn], vis[maxn], e[maxn];
int cnt;
using ll = long long;
ll bit_pow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
void Euler()
{
    cnt = 0;
    prime[cnt++] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
            prime[cnt++] = i;
        for (int j = 0; j < cnt && i * prime[j] < maxn; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void add_integer(int n, int d)
{
    for (int i = 1; i < cnt; i++)
    {
        while (n % prime[i] == 0)
        {
            n /= prime[i];
            e[i] += d;
        }
        if (n == 1)
            break;
    }
}
void add_fac(int n, int d)
{
    for (int i = 2; i <= n; i++)
    {
        add_integer(i, d);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Euler();
    int p, q, r, s;
    while (cin >> p >> q >> r >> s)
    {
        for (int i = 1; i < cnt; i++)
            e[i] = 0;
        add_fac(p, 1);
        add_fac(q, -1);
        add_fac(p - q, -1);
        add_fac(r, -1);
        add_fac(s, 1);
        add_fac(r - s, 1);
        double ans = 1;
        for (int i = 1; i < cnt; i++)
        {
            if (e[i] > 0)
            {
                ans = ans * bit_pow(prime[i], e[i]);
            }
            else if (e[i] < 0)
            {
                ans = ans / bit_pow(prime[i], -e[i]);
            }
        }
        cout << fixed << setprecision(5) << ans << '\n';
    }
}