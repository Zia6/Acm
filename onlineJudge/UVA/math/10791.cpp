#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 5;
int e[maxn];
int main()
{
    int n;
    int tot = 0;
    while (cin >> n && n)
    {
        long long ans = 0, cnt = 0;
        if (n == 1)
        {
            cout << "Case " << ++tot << ": ";
            cout <<2 << '\n';
            continue;
        }
        int nn = n;
        int k = floor(sqrt(n) + 0.5);
        for (int i = 2; i < k; i++)
        {
            int temp = 1;
            if (n % i == 0)
            {
                cnt++;
                while (n % i == 0)
                {
                    temp *= i;
                    n /= i;
                }
                ans += temp;
            }
        }
        if (n > 1)
        {
            ans += n;
            cnt += 1;
        }
        if (cnt == 1)
            ans += 1;
        cout << "Case " << ++tot << ": ";
        cout << ans << '\n';
    }
}