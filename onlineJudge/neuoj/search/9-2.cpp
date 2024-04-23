#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e6 + 5;
int index[maxn], v[maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        index[v[i]] = i;
    }
    int now = 1;
    long long ans = 0;
    while (now <= n)
    {
        ans++;
        int j = now + 1;
        while (j <= n && index[j] > index[j - 1])
        {
            j++;
        }
        now = j;
    }
    int x, y, a, b;
    while (m--)
    {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        x = v[a], y = v[b];
        if (y == x + 1)
        {
            ans++;
        }
        else
        {
            if (x < n && index[x] < index[x + 1] && b > index[x + 1])
            {
                ans++;
            }
            if (y > 1 && index[y] > index[y - 1] && a < index[y - 1])
            {
                ans++;
            }
        }
        if(y == x - 1){
            ans--;
        }else {
            if(y < n && index[y] > index[y + 1] && a < index[y + 1]){
                ans--;
            }
            if(x > 0 && index[x] < index[x - 1] && b > index[x - 1]){
                ans--;
            }
        }
        swap(index[x], index[y]);
        swap(v[a], v[b]);
        cout << ans << '\n';
    }
}