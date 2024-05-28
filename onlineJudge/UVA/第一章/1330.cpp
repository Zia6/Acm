#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <sstream>

template <class T>
inline void read(T &x)
{
    x = 0;
    int f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    x *= f;
}
using ll = long long;
const int maxn = 1e3 + 5;
int g[maxn][maxn], up[maxn][maxn],l[maxn][maxn],r[maxn][maxn];
void solve()
{
    int n, m;
    read(n), read(m);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        up[i][0] = up[i][m + 1] = 0;
        std:: stack<int> s;
        s.push(0);
        for (int j = 1; j <= m; j++)
        {
            up[i][j] = 0;
            char c;
            std::cin >> c;
            l[i][j] = 0;
            if (c == 'F')
            {
                g[i][j] = 1;
                up[i][j] = up[i - 1][j] + 1;
            }
            while(!s.empty() && up[i][s.top()] >= up[i][j]){
                s.pop();
            }
            if(!s.empty()){
                l[i][j] = j - s.top() - 1;
            }
            s.push(j);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        std::stack<int> s;
        s.push(m + 1);
        for(int j = m;j >= 1;j--){
            r[i][j] = 0;
            while(!s.empty() && up[i][s.top()] >= up[i][j]){
                s.pop();
            }
            if(!s.empty()){
                r[i][j] = s.top() - j - 1;
            }
            s.push(j);
            ans = std::max(up[i][j] * (l[i][j] + r[i][j] + 1),ans);
        }
    }
    std:: cout << 3 * ans << '\n';
}
int main()
{
    int T;
    read(T);
    while (T--)
    {
        solve();
    }
    return 0;
}