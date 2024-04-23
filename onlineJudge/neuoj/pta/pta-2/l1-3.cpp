#include <iostream>
#include <cstring>
using namespace std;
const int N = 1005;
struct node
{
    int st = -1;
    int en = -1;
} a[N];
int sto(string s)
{
    int t1 = 0, t2 = 0;
    for (int i = 0; i < 2; i++)
    {
        t1 *= 10;
        t1 += s[i] - '0';
    }
    for (int i = 3; i < 5; i++)
    {
        t2 *= 10;
        t2 += s[i] - '0';
    }
    return t1 * 60 + t2;
}
void solve()
{
    memset(a, -1, sizeof(a));
    int cnt = 0, sum = 0;
    int t;
    char flag;
    string s;
    while (cin >> t && t != 0)
    {
        getchar();
        cin >> flag;
        cin >> s;
        int m = sto(s);
        if (flag == 'S')
        {
            a[t].st = m;
        }
        else
        {
            if (a[t].st == -1)
            {
                continue;
            }
            else
            {
                cnt += 1;
                sum += m - a[t].st;
                a[t].st = 0;
            }
        }
        // cout<<"100"<<t<<' '<<flag<<' '<<s<<'\n';
    }
    getchar();
    cin >> flag;
    cin >> s;
    if (cnt == 0)
    {
        cout << 0 << ' ' << 0 << '\n';
        return;
    }
    int ans = sum / cnt;
    float x = 1.0 * sum / cnt;
    if (x - ans >= 0.5)
        ans++;
    cout << cnt << ' ' << ans << '\n';
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}