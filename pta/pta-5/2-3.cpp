#include <iostream>
using namespace std;
int ans[35];
int v[35];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ans[0] = n;
        }
        else
        {
            if (ans[i - 1] & 1)
            {
                ans[i] = ans[i - 1] >> 1;
            }
            else
            {
                if (ans[i - 1] + 1 <= n)
                {

                    int t = ans[i - 1] + 1;
                    while(t << 1 <= n){
                        t <<= 1;
                    }
                    ans[i] = t;
                }
                else
                    ans[i] = ans[i - 1] >> 1;
            }
        }
        // std::cout << ans[i] << ' ';
    }
    // std::cout << '\n';
    int t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        v[ans[i]] = t;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << v[i];
        if(i < n){
            cout << ' ';
        }
    }
}