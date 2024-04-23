#include <iostream>
#include <cstdio>
#include <algorithm>
#include<climits>
using namespace std;
const int N = 2e5 + 5;
int a[N];
long long sum[N],ans = 49955518418713;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n ; i++)
    {
        scanf("%d",&a[i]);
    }

    sort(a+1,a+n+1);
    for(int i = 1; i<=n; i++)
    {
        sum[i] = sum[i-1] + a[i];
    }
    // for(int i = 1; i <= n; i++)
    // {
    //     ans = min(ans,1ll*i*a[i] - sum[i] + sum[n] - sum[i] - 1ll * (n - i) * a[i]);
    // }
    int i = (n + 1) >> 1;
    printf("%lld\n",1ll*i*a[i] - sum[i] + sum[n] - sum[i] - 1ll * (n - i) * a[i]);
}