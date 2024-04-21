#include <iostream>
#include <cstring>
using namespace std;
const int N = 11;
int a[N], n;
void swap1(int i, int j, int k)
{
    int b[N];
    memcpy(b, a, sizeof(a));
    int ind = 0;
    for (ind = 0; ind < i; ind++)
    {
        a[ind] = b[ind];
    }
    for (ind = i; ind < i + k; ind++)
    {
        a[ind] = b[ind + j - i + 1];
    }
    for (ind = i + k; ind <= j + k; ind++)
    {
        a[ind] = b[ind - k];
    }
    for (ind = j + k + 1; ind < n; ind++)
    {
        a[ind] = b[ind];
    }
}
void swap2(int i, int j, int k)
{
    int b[N];
    memcpy(b, a, sizeof(a));
    int ii = 0;
    for (ii = 0; ii < i - k;ii++){
        a[ii] = b[ii];
    }
    for (ii = i - k; ii <= j - k;ii++){
        a[ii] = b[ii + k];
    }
    for (ii = j - k + 1; ii <= j;ii++){
        a[ii] = b[ii - 1 + i - j];
    }
}
bool ida(int d, int maxd)
{
    int h = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] != a[i] + 1)
        {
            h++;
        }
    }
    if (d > maxd || 3 * d + h > 3 * maxd)
    {
        return false;
    }
    if (h == 0)
    {
        return true;
    }
    int b[N];
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k=1; k+j < n; k++)
            {
                swap1(i, j, k);
                if(ida(d+1,maxd)){
                    return true;
                }
                swap2(i+k, j+k, k);

            }
            for (int k = 1; k <= i;k++){
                swap2(i, j, k);
                if (ida(d + 1, maxd))
                {
                    return true;
                }
                swap1(i - k, j - k, k);
            }
        }
    }
    return false;
}
void solve()
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0;i <= 9; i++)
    {
        if (ida(0, i))
        {
            cout << i << '\n';
            return;
        }
    }
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int cnt = 0;
    while (cin >> n && n)
    {
        cout << "Case " << ++cnt << ": ";
        solve();
    }
    // for (int i = 0; i < 9;i++){
    //     a[i] = i;
    // }
    // swap2(2, 3, 1);
    // for(int i = 0; i < 9;i++){
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
    // swap1(1, 2, 1);
    // for (int i = 0; i < 9; i++)
    // {
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
}