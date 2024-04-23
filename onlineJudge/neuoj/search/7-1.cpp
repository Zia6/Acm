#include <iostream>
#include <stack>
using namespace std;
const int maxn = 2e5 + 5;
stack<int> s;
int a[maxn];
int minx = 1e9 + 5;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        if(s.empty()){
            cout << 0 << ' ';
        }else
            cout << s.top() << ' ';
        s.push(i);
    }
}
