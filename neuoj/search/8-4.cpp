#include <iostream>
#include<cstring>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 2e5 + 5;
int n;
long long d[maxn << 1];
struct seg
{
    int l, r, index;
    bool operator<(const seg &s) const
    {
        return l == s.l ? r > s.r : l < s.l;
    }
} s[maxn];
int lowbit(int x)
{
    return x & -x;
}
long long gets(int x)
{
    long long ans = 0;
    while (x)
    {
        ans += d[x];
        x -= lowbit(x);
    }
    return ans;
}
void add(int index, int x)
{
    while (index <= (n << 1))
    {
        d[index] += x;
        index += lowbit(index);
    }
}
long long getsum(int l, int r)
{
    return gets(r) - gets(l - 1);
}
int a[maxn << 1], ans1[maxn], ans2[maxn];
map<int, int> mp;
int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].l >> s[i].r;
        s[i].index = i;
        a[i << 1] = s[i].l;
        a[i << 1 | 1] = s[i].r;
    }
    std::sort(a, a + (n << 1));
    int l = unique(a, a + (n << 1)) - a;
    for (int i = 0; i < l; i++)
    {
        mp.insert({a[i], i + 1});
    }
    for (int i = 0; i < n; i++)
    {
        s[i].l = mp[s[i].l];
        s[i].r = mp[s[i].r];
    }
    std::sort(s, s + n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << s[i].l << ' ' << s[i].r << '\n';
        ans2[s[i].index] = cnt - gets(s[i].r - 1);
        cnt++;
        add(s[i].r, 1);
    }
    memset(d, 0, sizeof(d));
    for (int i = n - 1; i >= 0;i--){
        ans1[s[i].index] = gets(s[i].r);
        add(s[i].r, 1);
    }
    for (int i = 0; i < n; i++)
    {
        cout << (ans1[i] == 0 ? 0 : 1);
        cout << (i == n - 1 ? '\n' : ' ');
    }
    for (int i = 0; i < n; i++)
    {
        cout << (ans2[i] == 0 ? 0 : 1);
        cout << (i == n - 1 ? '\n' : ' ');
    }
}