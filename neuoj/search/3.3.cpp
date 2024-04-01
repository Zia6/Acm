#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 1e9 + 5;
struct seg
{
    int x, y;
    bool operator<(const seg &s)
    {
        return x == s.x ? y < s.y : x < s.x;
    }
};
int a[maxn];
seg s[maxn];
int main()
{
    int n, x, y;
    scanf("%d", &n);
    for (int i = 0; i < maxn; i++)
        a[i] = inf;
    a[0] = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d\n", a[i]);
    // }
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        s[i].x = x, s[i].y = y;
    }
    sort(s, s + n);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d %d\n", s[i].x, s[i].y);
    // }
    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(a, a + n, s[i].x);
        *it = s[i].y;
        // printf("%d\n", it - a);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d\n", a[i]);
    // }
    for (int i = 1; i < maxn; i++)
    {
        if (a[i] < inf)
            continue;
        else
        {
            printf("%d\n", i - 1);
            return 0;
        }
    }
}