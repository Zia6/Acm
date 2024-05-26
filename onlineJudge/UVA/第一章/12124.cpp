#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <sstream>

template <class T>
inline void read(T &x)
{
    x = 0;
    int f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    x *= f;
}
struct node
{
    long long value;
    int quality;
};
const int maxn = 1e3 + 5;
std::map<std::string, int> mp;
std::vector<node> v[maxn];
bool check(int x, int cnt, int m)
{
    long long sum = 0;
    for (int i = 0; i < cnt; i++)
    {
        long long mx = 1e9 + 5;
        for (auto &nn : v[i])
        {
            if (nn.quality >= x && nn.value < mx)
            {
                mx = nn.value;
            }
        }
        if (mx == 1e9 + 5)
            return false;
        sum += mx;
    }
    // std:: cout << sum << '\n';
    return sum <= m;
}
int main()
{
    int T;
    read(T);
    while (T--)
    {
        long long n, m, cnt = 0;

        mp.clear();
        read(n);
        read(m);
        for (int i = 0; i < n; i++)
        {
            v[i].clear();
        }
        for (int i = 0; i < n; i++)
        {
            node nn;
            std::string s,ss;
            std::cin >> s;
            if (!mp.count(s))
            {
                mp[s] = cnt++;
            }
            std::cin >> ss;
            read(nn.value);
            read(nn.quality);
            v[mp[s]].push_back(nn);
        }
        int l = 0, r = 1e9 + 5;
        while (l < r)
        {
            int mid = l + ((r - l + 1) >> 1);
            // std:: cout << mid << '\n';
            if (check(mid, cnt, m))
            {
                l = mid;
            }
            else
                r = mid - 1;
        }
        std::cout << l << '\n';
    }
    return 0;
}