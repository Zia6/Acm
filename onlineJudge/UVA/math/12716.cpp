#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 3e7 + 5;
int f[maxn];
void solve(int n)
{
    for (int i = 1; i <= (n >> 1); i++)
    {
        for (int j = (i << 1); j <= n; j += i)
        {
            if ((i ^ j) == j - i)
            {
                f[j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        f[i] += f[i - 1];
}
int main()
{
    int T, n;
    cin >> T;
    solve(maxn - 1);
    for (int i = 1; i <= T; i++)
    {
        cin >> n;
        cout << "Case " << i << ": " << f[n] << '\n';
    }
}