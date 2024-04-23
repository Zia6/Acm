#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
multiset<int> s;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", a + i);
        s.insert(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        auto it = s.find(a[i]);
        s.erase(it);
        if (s.find(k - a[i]) != s.end())
        {
            for (int j = 0; j < n; j++)
            {
                if (a[j] == k - a[i] && i != j)
                {
                    printf("%d %d", i + 1, j + 1);
                    return 0;
                }
            }
        }
        s.insert(a[i]);
    }
    printf("IMPOSSIBLE");
}