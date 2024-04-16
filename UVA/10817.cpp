#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
const int maxn = 125;
const int maxs = 8;
const int inf = 1e8;
int a[maxn], sub[maxn], d[maxn][1 << maxs][1 << maxs];
int s, m, n;
// s0 没人教 s1 一个老师教 s2 两个老师教
// d[i][s1][s2] = min(d[i + 1][s1][s2],d[i+1])
int dp(int i, int s0, int s1, int s2)
{
    if (i == m + n)
        return s2 == (1 << s) - 1 ? 0 : inf;
    int &ans = d[i][s1][s2];
    if (ans >= 0)
        return ans;
    ans = inf;
    if (i >= m)
    {
        ans = dp(i + 1, s0, s1, s2);
    }
    int m0 = sub[i] & s1, m1 = sub[i] & s0;
    s2 |= (m0), s0 ^= m1, s1 = (s1 ^ m0) | m1;
    ans = min(ans, a[i] + dp(i + 1, s0, s1, s2));
    return ans;
}
int main()
{

    while (cin >> s >> m >> n && s)
    {
        getchar();
        string st;
        for (int i = 0; i < maxn; i++)
        {
            sub[i ] = 0;
            for (int j = 0; j < 1 << maxs; j++)
            {
                for (int k = 0; k < 1 << maxs; k++)
                {
                    d[i][j][k] = -1;
                }
            }
        }
        for (int i = 0; i < m + n; i++)
        {
            getline(cin, st);
            stringstream ss;
            ss << st;
            ss >> st;
            a[i] = stoi(st);
            while (ss >> st)
            {
                sub[i] |= (1 << (stoi(st) - 1));
            }
            // cout << a[i] << ' ' << sub[i] << '\n';
        }
        int s0 = (1 << s) - 1, s1 = 0, s2 = 0;
        cout << dp(0, s0, s1, s2) << '\n';
    }
}