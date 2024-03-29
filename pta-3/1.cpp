#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
const int N = 105;
int in[N], cnt[N], cnt2[N];
int ans[N][N];
struct node
{
    int index;
    int value;
    bool operator<(const node &n) const
    {
        return index < n.index;
    }
};
signed main()
{
    int n, ma = 1;
    cin >> n;
    int sum = 0;
    int s = 0;
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> cnt[i];
        cnt[i] *= 10;
        sum += cnt[i];
        cnt2[i] = cnt[i];
        in[i] = 1;
        if (cnt[ma] < cnt[i])
            ma = i;
    }
    if(n==1){
        cout << "#1\n";
        for (int i = 1; i <= cnt[1];i++){
            cout << i * 2 - 1;
            if(i%10==0)
                cout << '\n';
                else
                    cout << ' ';
        }
        return 0;
    }
    sort(cnt2 + 1, cnt2 + n + 1);
    s = sum - cnt2[n] + cnt2[n - 1];
    // cout << s << '\n';
    for (int i = 1; i <= s; i++)
    {
        while (in[k] > cnt[k])
        {
            k++;
            if (k > n)
                k -= n;
        }
        ans[k][in[k]] = i;
        in[k]++;
        k++;
        if(k>n)
            k -= n;
    }
    if(ans[ma][in[ma]-1]!=s){
        ans[ma][in[ma]] = s + 1;
    }else
        ans[ma][in[ma]] = s + 2;
    for (int i = in[ma]+1; i <= cnt[ma]; i++)
    {
        ans[ma][i] = ans[ma][i - 1] + 2;
    }
    for (int i = 1; i <= n;i++){
        cout << "#" << i << '\n';
        for (int j = 1; j <= cnt[i];j++){
            cout << ans[i][j];
            if(j%10==0)
                cout << '\n';
                else
                    cout << ' ';
        }
    }
}