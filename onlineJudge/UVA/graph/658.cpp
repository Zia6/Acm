    #include <iostream>
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
    using namespace std;
    const int maxn = 1e7 + 5;
    const int inf = 1e9 + 5;
    int d[maxn], t[maxn];
    string s[maxn], en[maxn];
    void solve(int n, int m)
    {
        for (int i = 0; i <= (1 << n); i++)
        {
            d[i] = inf;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> t[i] >> s[i] >> en[i];
        }
        // 使用 greater<> 来创建最小堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        d[(1 << n) - 1] = 0;
        q.push({0, (1 << n) - 1});
        while (!q.empty())
        {
            pair<int, int> u = q.top();
                    // cout << u.second << ' ' << u.first << '\n';
            q.pop();
            if (u.second == 0)
            {
                cout << "Fastest sequence takes " << d[u.second] << " seconds." << '\n';
                return;
            }
            for (int i = 0; i < m; i++)
            {
                bool flag = true;
                string ss = s[i];
                for (int j = 0; j < n; j++)
                {
                    int now = u.second >> j & 1;
                    if (ss[n - 1 - j] == '+')
                    {
                        if (now != 1)
                        {
                            flag = false;
                            break;
                        }
                    }
                    else if (ss[n - 1 - j] == '-')
                    {
                        if (now != 0)
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag == false)
                    continue;
                // cout << u.second << '\n';
                int v = u.second;
                ss = en[i];
                for (int j = 0; j < n; j++)
                {
                    if (ss[n - 1 - j] == '-')
                    {
                        v &= ~(1 << j); // 将第 j 位设置为 0
                    }
                    else if (ss[n - 1 - j] == '+')
                    {
                        v |= (1 << j);
                    }
                }
                if (d[u.second] + t[i] < d[v])
                {
                    d[v] = d[u.second] + t[i];
                    q.push({d[v], v});
                }
            }
        }
        cout << "Bugs cannot be fixed.\n";
    }
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n, m,cnt = 0;
        while (cin >> n >> m && n && m)
        {
            cout << "Product " << ++cnt << '\n';
            solve(n, m);
            cout << '\n';
        }
        return 0;
    }