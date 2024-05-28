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
using ll = long long;
#define mp std::make_pair
#define pr std::pair
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
const int maxn = 105;
pr<int, int> p[maxn];
int row[maxn], on[maxn], on2[maxn], left[maxn];
int solve(int n)
{
    for (int i = 0; i < n; i++)
    {
        read(p[i].first), read(p[i].second);
        row[i] = p[i].second;
    }
    std::sort(row, row + n);
    std::sort(p, p + n);
    int l = std::unique(row, row + n) - row;
    int ans = 0;
    if (l <= 2)
        return n;
    for (int i = 0; i < l; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            int ymin = row[i], ymax = row[j];
            int cnt = 0;
            for (int k = 0; k < n; k++)
            {
                if (k == 0 || p[k].first != p[k - 1].first)
                {
                    cnt++;
                    on[cnt] = on2[cnt] = 0;
                    if (cnt > 0)
                        left[cnt] = left[cnt - 1] + on2[cnt - 1] - on[cnt - 1];
                    else
                        left[cnt] = 0;
                }
                if (p[k].second >= ymin && p[k].second <= ymax)
                    on2[cnt]++;
                if (p[k].second > ymin && p[k].second < ymax)
                    on[cnt]++;
                int mx = 0;
                for (int k = 0; k < cnt; k++)
                {
                    ans = std::max(ans, left[k] + on2[k] + mx);
                    mx = std::max(mx, on[k] - left[k]);
                }
            }
            if (cnt <= 2)
                return n;
        }
    }
    return ans;
}

int main()
{
    int n, cnt = 0;
    while (std::cin >> n && n)
    {
        int ans = solve(n);
        std::cout << "Case " << ++cnt << ": " << ans << '\n';
    }
    return 0;
}