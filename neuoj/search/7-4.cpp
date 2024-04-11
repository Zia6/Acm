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
    long long ans = 0;
    mp.insert({0, 1});
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = (a[i] + pre[i - 1]) % n;
        pre[i] = (pre[i] + n) % n;
        if (mp.count(pre[i]))
        {
            ans += mp[pre[i]];
        }
        mp[pre[i]]++;
    }
    cout << ans << '\n';
}
