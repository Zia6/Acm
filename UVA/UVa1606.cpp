#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1005;
int color[maxn];
struct vec
{
    int x;
    int y;
    int operator^(const vec &v) const
    {
        return x * v.y - y * v.x;
    }
    vec operator+(const vec &v) const
    {
        return {x + v.x, y + v.y};
    }
    vec operator-(const vec &v) const
    {
        return {x - v.x, y - v.y};
    }
} v[maxn], ve;
struct node
{
    int index;
    int value;
    bool operator<(const node &n) const
    {
        return value < n.value;
    }
} a[maxn];
int tem = 0, cnt1 = 0, cnt2 = 0, ans = 0;
void solve()
{
    int n;
    while (scanf("%d", &n) != EOF && n)
    {
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &v[i].x, &v[i].y, &color[i]);
            if (color[i])
                cnt1++;
            else
                cnt2++;
        }
        for (int i = 0; i < n; i++)
        {
            int cnt3 = 0, cnt4 = n - cnt1;
            ve.x = v[i].x, ve.y = 0;
            for (int j = 0; j < n; j++)
            {
                a[j].value = ((v[j] - v[i]) ^ ve);
                a[j].index = j;
            }
            sort(a, a + n);
            for (int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;
                if (color[a[j].index])
                {
                    cnt3++;
                    ans = max(ans, cnt3 + cnt4);
                }
                else
                {
                    ans = max(ans, cnt3 + cnt4);
                    cnt4--;
                }
            }
        }
        printf("%d\n", ans);
    }
}
int main()
{
    solve();
}