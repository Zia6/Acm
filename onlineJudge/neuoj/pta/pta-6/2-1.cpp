#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
const int maxn = 1e2 + 3;
queue<char> q[maxn];
stack<char> s;
int main()
{
    int n, m, M;
    cin >> n >> m >> M;
    getchar();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            q[i].push(c);
        }
        getchar();
    }
    int op;
    while (cin >> op && op != -1)
    {
        if (op == 0)
        {
            if (!s.empty())
            {
                cout << s.top();
                s.pop();
            }
        }
        else
        {
            if (!q[op].empty())
            {
                if (s.size() == M)
                {
                    cout << s.top();
                    s.pop();
                }
                char now = q[op].front();
                q[op].pop();
                s.push(now);
            }
        }
    }
}