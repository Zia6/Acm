#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 5e3 + 5;
int cnt[maxn][maxn], dp[maxn][maxn], st[2][27], en[2][27], l[2], tmp[27];
const int inf = 1e9 + 5;
string s[2];
void solve()
{
    for (int i = 0; i < 2; i++)
    {
        memset(st[i], inf, sizeof(st[i]));
        memset(en[i], -1, sizeof(en[i]));
        cin >> s[i];
        l[i] = s[i].length();
        st[i][s[i][0] - 'A'] = 0;
        en[i][s[i][0] - 'A'] = 0;
        for (int j = 0; j < l[i]; j++)
        {
            if (st[i][s[i][j] - 'A'] == 84215045)
            {
                st[i][s[i][j] - 'A'] = j;
            }
            en[i][s[i][j] - 'A'] = j;
            tmp[s[i][j] - 'A']++;
        }
    };
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 26;j++){
    //         std::cout << tmp[s[i][j] - 'A'] << ' ';
    //     }
    //     std::cout << '\n';
    // }
    std::cout << l[0] << ' ' << l[1] << '\n';
    for (int i = 0; i < l[0]; i++)
    {
        for (int j = 0; j < l[1]; j++)
        {
            cnt[i][j] = inf;
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    cnt[0][0] = 0;
    if(s[0][0] == s[1][0]){
        dp[0][0] = 1;
        int x = s[0][0] - 'A';
        if(tmp[x] > 2){
            cnt[0][0] = 1;
        }
    }else {
        int x = s[0][0] - 'A', y = s[1][0] - 'A';
        if(tmp[x] >= 2){
            cnt[0][0]++;
        }
        if(tmp[y] >= 2){
            cnt[0][0]++;
        }
    }
    for (int i = 0; i < l[0]; i++)
    {
        for (int j = 0; j < l[1]; j++)
        {
            if (i > 0)
            {
                int x = s[0][i] - 'A';
                cnt[i][j] = cnt[i - 1][j];
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + cnt[i - 1][j]);
                if (tmp[x] >= 2)
                {
                    {
                        if (st[0][x] == i && st[1][x] > j)
                        {
                            cnt[i][j]++;
                        }
                        if (en[0][x] == i && en[1][x] <= j)
                        {
                            cnt[i][j]--;
                        }
                    }
                }
            }
            if (j > 0)
            {
                int x = s[1][j] - 'A';
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + cnt[i][j - 1]);
                cnt[i][j] = cnt[i][j - 1];
                if (tmp[x] >= 2)
                {
                    if (st[1][x] == j && st[0][x] > i)
                    {
                        cnt[i][j]++;
                    }
                    if (en[1][x] == j && en[0][x] <= i)
                    {
                        cnt[i][j]--;
                    }
                }
            }
            std::cout << i << ' ' << j << ' ' << cnt[i][j] << ' ' << dp[i][j] << '\n';
        }
    }
    std::cout << dp[l[0] - 1][l[1] - 1] << '\n';
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
}