#include <cstdio>
#include <queue>
#include <iostream>
#include <stack>
using namespace std;
stack<int> q;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    while (k--)
    {
        bool flag = false;
        int cnt = 1;
        for (int i = 1; i <= n; i++)
        {
            int t;
            cin >> t;
            q.push(t);
            while (!q.empty() && q.top() == cnt)
            {
                // cout << i << ' ' << cnt << ' ';
                q.pop();
                cnt++;
            }
            if ((int)q.size() > m)
                flag = true;
        }
        if (flag || !q.empty())
        {
            cout << "NO" << '\n';
            while (!q.empty())
            {
                q.pop();
            }
        }
        else
            cout << "YES" << '\n';
    }
}