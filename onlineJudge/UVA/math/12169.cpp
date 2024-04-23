#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int mod = 10001;
const int maxn = 1e4 + 5;
long long v[maxn], tem[maxn];
ll bit_pow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
// x * a * a + a * b + b
// a ^ 2 * x + b * (a + 1)
int main()
{
    ll a, b;
    int n;
    cin >> n;
    for (int i = 1; i < (n << 1); i += 2)
    {
        cin >> v[i];
        tem[i] = v[i];
    }
    for (a = 0; a < mod; a++)
    {

        for (b = 0; b < mod; b++)
        {
            bool flag = true;
            // cout << a << ' ' << b << '\n';
            for (int i = 2; i <= (n << 1); i++)
            {
                v[i] = (a * v[i - 1] + b) % mod;
                if ((i & 1) && v[i] != tem[i])
                {
                    v[i] = tem[i];
                    flag = false;
                    break;
                }
            }
            // cout << v[2] << '\n';
            if (flag)
            {
                for (int i = 2; i <= (n << 1); i += 2)
                {
                    cout << v[i] << '\n';
                }
                return 0;
            }
        }
    }
}