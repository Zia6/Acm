#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
long long a[maxn], dp[maxn];
int main()
{
    int n;
    long long ans = -1e9 - 5;
    cin >> n;
    cin >> dp[0];
    ans = max(ans, dp[0]);
    for (int i = 1; i < n; i++)
    {
        long long t;
        cin >> t;

        dp[i] = max(dp[i - 1] + t, t);
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}