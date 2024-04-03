#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int prime[N];
int vis[N];
void euler()
{
    int cnt = 0;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i
        {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * prime[j] < N; j++)       
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
// 判断是否是质数
#include <iostream>
using namespace std;
bool isprime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int T;
    cin >> T;
    euler();
    while (T--)
    {
        int t;
        cin >> t;
        if (t < N)
        {
            if (!vis[t])
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            int flag = 0;
            for (int i = 0; prime[i]!=0&&prime[i] * prime[i] <= t; i++)
            {
                if (t % prime[i] == 0)
                {
                    flag = 1;
                    cout << "No" << endl;
                    break;
                }
            }
            if (!flag)
            {
                cout << "Yes" << endl;
            }
        }
    }
}