#include <cstdio>
#include <iostream>
#include<climits>
using namespace std;
int n, k;
const int maxn = 2e5 + 5;
long long a[maxn];
bool solve(long long m)
{
    long long sum = 0, cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] > m)
        {
            sum = a[i];
            cnt++;
        }
        else
            sum += a[i];
    }
    return cnt <= k;
}
int main()
{
    scanf("%d %d", &n, &k);
    long long l = 0, r = LONG_LONG_MAX;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        l = max(l, a[i]);
    }
    while (l < r)
    {
        long long mid = l + ((r - l)>> 1);
        if (solve(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%lld", l);
}