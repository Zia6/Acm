#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
long long pre[maxn];
long long in[maxn];
map<long long, long long> mp;
vector<long long> v;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
        }
    }
    long long ans = 0;
    mp.insert({0, 1});
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = a[i] + pre[i - 1];
        for (long long x : v)
        {
            if (mp.count(pre[i] - x))
            {
                ans += mp[pre[i] - x];
            }
        }
        mp[pre[i]]++;
    }
    cout << ans << '\n';
}
