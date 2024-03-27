#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
struct heap1
{
    priority_queue<int, vector<int>, greater<int>> q1;
    priority_queue<int, vector<int>, greater<int>> del;
    void _del(int x)
    {
        del.push(x);
    }
    void _push(int x)
    {
        q1.push(x);
    }
    int _top()
    {
        while (!del.empty() && !q1.empty() && q1.top() == del.top())
        {
            q1.pop();
            del.pop();
        }
        return q1.top();
    }
    void _pop()
    {
        _top();
        q1.pop();
    }
    int _size()
    {
        return (int)q1.size() -(int) del.size();
    }
} h1;
struct heap2
{
    priority_queue<int, vector<int>, less<int>> q2;
    priority_queue<int, vector<int>, less<int>> del;
    void _del(int x)
    {
        del.push(x);
    }

    void _push(int x)
    {
        q2.push(x);
    }
    int _top()
    {
        while (!del.empty() && !q2.empty() && q2.top() == del.top())
        {
            q2.pop();
            del.pop();
        }
        return q2.top();
    }
    void _pop()
    {
        _top();
        q2.pop();
    }
    int _size()
    {
        return (int)q2.size() -(int)del.size();
    }
} h2;
int n, k, a[maxn];
void insert(int x)
{
    if (h2._size() && x < h2._top())
    {
        h2._push(x);
    }
    else
        h1._push(x);
    while (h2._size() > ((k + 1) >> 1))
    {
        int t = h2._top();
        h2._pop();
        h1._push(t);
    }
    while (h1._size() && h2._size() < ((k + 1) >> 1))
    {
        int t = h1._top();
        h1._pop();
        h2._push(t);
    }
}
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", a + i);
        insert(a[i]);
    }
    printf("%d ", h2._top());
    for (int i = k; i < n; i++)
    {
        if (a[i - k] <= h2._top())
        {
            h2._del(a[i - k]);
        }
        else
            h1._del(a[i - k]);
        scanf("%d", a + i);
        insert(a[i]);

        printf("%d ", h2._top());
    }
}