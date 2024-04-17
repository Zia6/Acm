#include <iostream>
using namespace std;
const int maxs = 11;
const int maxn = 128;
long long w[maxn], m, n;
long long d[1 << maxs][1 << maxs];
void init(){
    for (int i = 0; i < 1 << maxs;i++){
        for (int j = 0; j < 1 << maxs;j++){
            d[i][j] = -1;
        }
    }
}
// d[s][a] = max(d[s + k][a + k],d[s + k][a]) + 1;
long long dp(int s, int a)
{
    long long &ans = d[s][a];
    if (ans >= 0)
        return ans;
    ans = 0x3f3f3f3f;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if ((w[i] & s) == a)
            cnt++;
    }
    if (cnt <= 1){
        ans = 0;
        return ans;
    }
        
    for (int k = 0; k < m;k++){
        if(s & (1ll << k))
            continue;
        long long t = 1ll << k;
        ans = min(max(dp(s | t, a | t), dp(s | t, a)),ans);
    }
    ans += 1;
    return ans;
}
int main()
{
    while (cin >> m >> n && m)
    {
        init();
        char c;
        for (int i = 0; i < n; i++)
        {
            w[i] = 0;
            for (int j = 0; j < m;j++){
                cin >> c;
                if(c == '1')
                    w[i] |= (1ll << j);
            }
        }
        cout << dp(0, 0) << '\n';
    }
}