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
const int maxn = 65;


long long f(int a[],int x, int y)
{
    if (x == 0)
        return 0;
    if (a[x] == y)
        return f(a,x - 1, y);
    else
        return f(a,x - 1, 6 - y - a[x]) + (1ll << x - 1);
}
int a[maxn], b[maxn];
int main()
{
    int n, cnt = 1;
    while (std::cin >> n && n)
    {
        std::cout << "Case " << cnt++ << ": ";
        int now = 0;
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            read(b[i]);
            if (a[i] != b[i])
                now = i;
        }
        if (now)
            std::cout << f(a,now - 1, 6 - a[now] - b[now]) + f(b,now - 1, 6 - a[now] - b[now]) + 1 << '\n';
        else
            std::cout << 0 << '\n';
    }
    return 0;
}