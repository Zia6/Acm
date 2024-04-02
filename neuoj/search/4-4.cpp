#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
struct movie
{
    int st, en;
    bool operator<(const movie &m) const
    {
        return en < m.en;
    }
} mo[maxn];
multiset<int> s;
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &mo[i].st, &mo[i].en);
    }
    sort(mo, mo + n);
    int ans = 0;
    for (int i = 0; i < k; i++)
        s.insert(0);
    for (int i = 0; i < n; i++)
    {
        auto it = s.upper_bound(mo[i].st);
        if(it == s.begin())
            continue;
        else {
            it--;
            s.erase(it);
            s.insert(mo[i].en);
            ans++;
        }
    }
    printf("%d", ans);
}