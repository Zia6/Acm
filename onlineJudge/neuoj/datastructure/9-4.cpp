#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], ans[maxn];
queue<int> q;
int cnt = 1;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    q.push(1);
    cnt = 2;
    ans[1] = a[1];
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u * 2 <= n)
        {
            ans[u * 2] = a[cnt++];
            q.push(u << 1);
        }
        if (u * 2 + 1 <= n)
        {
            ans[u * 2 + 1] = a[cnt++];
            q.push((u << 1) + 1);
        }
    }
    for (int i = 1; i <= n;i++){
        printf("%d ", a[i]);
    }
}