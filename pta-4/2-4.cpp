#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
queue<int> q;
int main()
{
    int n, m, k;
    bool flag = false;
    while (k--)
    {

        int cnt = 1;
        for (int i = 1; i <= n; i++)
        {
            while (!q.empty() && q.front() == cnt)
            {
                q.pop();
                cnt++;
            }
            int t;
            cin >> t;
            if (t == cnt)
            {
                cnt++;
                continue;
            }
            else
            {
                q.push(t);
            }
            if (q.size() > m)
            {
                break;
            }
        }
        if (q.size() > m)
        {
            cout << "NO" << '\n';
            while(!q.empty()){
            q.pop();
        }
            continue;
        }
        while (!q.empty() && q.front() == cnt)
        {
            cnt++;
        }
        if(!q.empty()){
            cout << "YES" << '\n';
        }
        while(!q.empty()){
            q.pop();
        }
    }
}