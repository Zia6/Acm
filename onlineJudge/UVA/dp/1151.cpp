#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
const int maxn = 31;
int ans = 1e9 + 5;
int n, m;
int a[maxn], pre[maxn];
void dfs(int x, int cnt, int sum)
{
    if (sum > m || sum + pre[x] < m){
        return;
    }
    if(sum == m){
        ans = min(ans, cnt);
        return;
    }
    dfs(x + 1, cnt, sum + a[x]);
    dfs(x + 1, cnt, sum);
    dfs(x + 1, cnt + 1, sum + (a[x] >> 1));
}
signed main()
{

    cin >> n >> m;
    m <<= 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] <<= 1;
    }
    sort(a + 1, a + n + 1,greater<int>());
    for (int i = n; i >= 0; i--)
    {
        pre[i] = pre[i + 1] + a[i];
    }
    dfs(0, 0, 0);
    ans = ans == 1e9 + 5 ? -1 : ans;
    cout << ans << '\n';
}