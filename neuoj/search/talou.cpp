#include <iostream>
#include <cstdio>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
const int maxn = 2e5 + 5;
int a[maxn];
using namespace std;
multiset <int> s;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    { 
        auto it = upper_bound(s.begin(), s.end(), a[i]);
        if (it != s.end())
        {
            s.erase(it);
        }
        s.insert(a[i]);
    }
    // for(auto i : s)
    //     printf("%d", i);
    printf("%d\n", s.size());
}