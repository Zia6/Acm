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
const int maxn = 1e5 + 5;
struct node
{
    int value;
    int index;
    bool operator<(const node &n) const
    {
        return value < n.value;
    }
} a[maxn];
struct point
{
    int value;
    char dir;
    bool operator<(const point &n) const
    {
        return value < n.value;
    }
};
point ans[maxn];
int main()
{
    int N, L, T, n;
    read(N);
    for (int cnt = 1; cnt <= N; cnt++)
    {
        read(L);
        read(T);
        read(n);
        std::vector<point> v;
        for (int i = 0; i < n; i++)
        {
            char c;
            read(a[i].value);
            std::cin >> c;
            if (c == 'R')
            {
                v.push_back({std::min(a[i].value + T, L + 1), c});
            }
            else
            {
                v.push_back({std::max(a[i].value - T, -1), c});
            }
            a[i].index = i;
        }
        std::sort(v.begin(), v.end());
        std::sort(a, a + n);
        for (int i = 0; i < n; i++)
        {
            ans[a[i].index] = v[i];
            if (v[i].value >= 0 && v[i].value <= L)
            {
                if (i > 0)
                {
                    if (v[i].value == v[i - 1].value)
                    {
                        ans[a[i].index].dir = 'A';
                    }
                }
                if (i < n - 1)
                {
                    if (v[i].value == v[i + 1].value)
                    {
                        ans[a[i].index].dir = 'A';
                    }
                }
            }
        }
        std::cout << "Case #" << cnt << ":\n";
        for (int i = 0; i < n; i++)
        {
            if (ans[i].value < 0 || ans[i].value > L)
            {
                std::cout << "Fell off\n";
            }
            else
            {
                std::cout << ans[i].value << ' ';
                if (ans[i].dir == 'A')
                    std::cout << "Turning" << '\n';
                else
                    std::cout << ans[i].dir << '\n';
            }
        }
        std::cout << '\n';
    }
    return 0;
}