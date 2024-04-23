#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn << 1], te[maxn << 1];
int x[maxn], y[maxn];
int ans[maxn << 1];
map<int, int> mp;
int main()
{
    int n;
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
        te[cnt++] = x[i];
        te[cnt++] = y[i];
    }
    for (int i = 0; i < cnt; i++)
    {
        a[i] = te[i];
    }
    sort(te, te + cnt);
    for (int i = 0; i < cnt; i++)
    {
        mp[a[i]] = lower_bound(te, te + cnt, a[i]) - te + 1;
    }
    for (int i = 0; i < n;i++){
        ans[mp[x[i]]] += 1;
        ans[mp[y[i]] + 1] -= 1;
    }
    long long sum = 0;
    long long aans = 0;
    for (int i = 1; i <= cnt;i++){
        sum += ans[i];
        aans = max(aans, sum);
    }
    printf("%d\n", aans);
}