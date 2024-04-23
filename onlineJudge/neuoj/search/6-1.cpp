#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int main(){
    int n;
    long long ans = 0;
    cin >> n;
    int dur, dead;
    for (int i = 0; i < n;i++){
        cin >> a[i] >> dead;
        ans += 1ll * dead;
    }
    sort(a, a + n,greater<int>());
    for (int i = 0; i < n;i++){
        ans -= 1ll * a[i] * (i + 1);
    }
    cout << ans << '\n';
}