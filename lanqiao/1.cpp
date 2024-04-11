#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 1e4 + 5;
vector<int> v1, v2, v3, v4, ans;
int main()
{
    string s1, s2;

    cin >> s1 >> s2;
    if (s1[0] == '-')
        s1 = s1.substr(1);
    if (s2[0] == '-')
        s2 = s2.substr(1);

    // cout << s1 << ' ' << s2;
    if ((s1.size() < s2.size()) || (s1.size() == s2.size() && s1 < s2))
    {
        swap(s1, s2);
        cout << '-';
    }
    int l1 = s1.size(), l2 = s2.size();
    for (int i = 0; i < l1; i++)
    {
        v1.push_back(s1[l1 - 1 - i] - '0');
    }
    for (int i = 0; i < l2; i++)
    {
        v2.push_back(s2[l2 - 1 - i] - '0');
    }
    // for (int i = 0; i < v1.size(); i++)
    // {
    //     cout << v1[i];
    // }
    // cout << '\n';
    v3.resize(maxn, 0), v4.resize(maxn, 0);
    ans.resize(maxn, 0);
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v1.size(); j++)
        {
            v3[i + j] += v1[i] * v1[j];
            v3[i + j + 1] += v3[i + j] / 10;
            v3[i + j] %= 10;
        }
    }
    int cnt = 1005;
    while (cnt >= 1 && v3[cnt] == 0)
        cnt--;
    // for (int i = 0; i <= cnt; i++)
    // {
    //     cout << v3[cnt - i];
    // }
    // cout << '\n';
    for (int i = 0; i < l2; i++)
    {
        for (int j = 0; j < l2; j++)
        {
            v4[i + j] += v2[i] * v2[j];
            v4[i + j + 1] += v4[i + j] / 10;
            v4[i + j] %= 10;
        }
    }
    int m = 0;
    for (int i = 0; i <= cnt; i++)
    {
        ans[i] = m + v3[i] - v4[i];
        m = (ans[i] >= 0 ? 0 : -1);
        ans[i] = (ans[i] + 10) % 10;
    }
    cnt = 1000;
    while (cnt >= 1 && ans[cnt] == 0)
        cnt--;
    for (int i = 0; i <= cnt; i++)
    {
        cout << ans[cnt - i];
    }
}