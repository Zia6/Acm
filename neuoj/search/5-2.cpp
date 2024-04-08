#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5e3 + 5;
pair<int, int> a[maxn];
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        a[i].first = t;
        a[i].second = i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int w = k - a[i].first - a[j].first;
            int l = 0, r = n - 1, mid;
            while (l < r)
            {
                mid = l + ((r - l) >> 1);
                if (a[mid].first >= w)
                    r = mid;
                else
                    l = mid + 1;
            }
            if(l >= n || l < 0)
                continue;
            if (a[r].first == w)
            {
                while (r < n && a[r].first == w && (r == i || r == j))
                {
                    r++;
                }
                if (r < n && a[r].first == w && r != i && r != j)
                {
                    printf("%d %d %d", a[i].second + 1, a[j].second + 1, a[r].second + 1);
                    return 0;
                }
            }
        }
    }
    printf("IMPOSSIBLE\n");
}