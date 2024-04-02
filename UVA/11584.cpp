#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e3 + 5;
bool huiwen[maxn][maxn];
int dp[maxn];
void check(string &s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            huiwen[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(i < n - 1 && s[i] == s[i+1])
            huiwen[i][i + 1] = true;
        huiwen[i][i] = true;
    }
    for (int i = 0; i < n; i++)
    {
    }
    for (int l = n; l >= 0; l--)
    {
        for (int r = l; r < n; r++)
        {
            if (s[l] == s[r] && huiwen[l + 1][r - 1])
            {
                huiwen[l][r] = true;
                // cout << l << r << '\n';
            }
        }
    }
    // for (int j = 0; j < n; j++)
    // {
    //     for (int k = j; k < n; k++)
    //     {
    //         if (huiwen[j][k])
    //             cout << j << ' ' << k << '\n';
    //     }
    // }
}
int main()
{
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        check(s);
        int ll = s.length();
        memset(dp, 10000, sizeof(dp));
        for (int j = 0; j < ll; j++)
        {
            if(huiwen[0][j])
                dp[j] = 1;
            for (int k = 0; k < j; k++)
            {
                if (huiwen[k + 1][j])
                {
                    dp[j] = min(dp[k] + 1, dp[j]);
                }
            }
        }
        // for (int j = 0; j < ll;j++){
        //     cout << dp[j] << ' ';
        // }
            cout << dp[ll - 1] << '\n';
    }
}