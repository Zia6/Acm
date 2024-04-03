#include <iostream>
#include <vector>
using namespace std;
const int N = 1005;
bool bro[N];
double a[N][N];
int t1[N], t2[N];
vector<int> ans1, ans2;
int main()
{
    int n, m, c, d;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int cnt, t;
        cin >> cnt;
        int cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < cnt; j++)
        {
            cin >> t;
            if (t < 0)
            {
                t = -t;
                bro[t] = true;
  
                t1[cnt1++] = t;
            }
            else
                t2[cnt2++] = t;
        }
        for (int j = 0; j < cnt1; j++)
        {
            for (int w = 0; w < cnt2; w++)
            {
                int tt1 = t1[j], tt2 = t2[w];
                a[tt1][tt2] += (1.0 / cnt);
                a[tt2][tt1] += (1.0 / cnt);
            }
        }
    }
    // for (int i = 0; i < n;i++){
    //     for (int j = 0; j < n;j++){
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
        cin >> c >> d;
    int w1, w2;
    w1 = c, w2 = d;
    if (c < 0)
        c = -c;
    if (d < 0)
        d = -d;
    double ma = 0;
    bool flag1 = false, flag2 = false;
    for (int i = 0; i < n; i++)
    {
        if ( ma < a[c][i])
        {
            // cout << c << ' ' << i << '\n';
            ma = a[c][i];
        }
    }
    // cout << ma << '\n';
    for (int i = 0; i < n; i++)
    {
        if ( ma == a[c][i])
            ans1.push_back(i);
    }
    if (a[c][d] == ma)
        flag1 = true;
    ma = 0;
    for (int i = 0; i < n; i++)
    {
        if (bro[d] != bro[i] && ma < a[d][i])
        {
            // cout << d << ' ' << i << '\n';
            ma = a[d][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (bro[d] != bro[i] && a[d][i] == ma)
            ans2.push_back(i);
    }
    if (a[d][c] == ma)
    {
        flag2 = true;
    }
    if (flag1==true && flag2==true)
    {
        cout << w1 << ' ' << w2;
        return 0;
    }
    // cout << ans1.size() << ' ' << ans2.size() << '\n';
    // cout << w1 << ' ';
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << w1 << ' ';
        if (bro[ans1[i]])
            cout << '-';
        cout << ans1[i]<<'\n';
    }


    for (int i = 0; i < ans2.size(); i++)
    {
            cout << w2 << ' ';
        if (bro[ans2[i]])
            cout << '-';
        cout << ans2[i] << '\n';
    }
}