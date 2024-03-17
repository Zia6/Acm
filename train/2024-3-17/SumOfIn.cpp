#include<iostream>
#include <cmath>
using namespace std;
#define int long long
using ll = long long;
const int mod = 1e9 + 7;
void init(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll bit_pow(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b&1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void solve(){
    ll n;
    cin>>n;
    ll ans = 0;
    ll mo=bit_pow(2,mod-2);
    int tem = sqrt(n);
    for (int i = 1; i <= n/tem;i++){
        ans =(ans+ n / i%mod * i%mod)%mod;
    }
    for (int i = tem-1;i>=1;i--){
        int r = (n /i)%mod;
        int l = (n/(i+1)+1)%mod;
        ans += (ll)(r - l + 1)%mod * (l + r)%mod*mo%mod * i%mod;
        ans =(ans+ mod)%mod;
    }
    cout << ans << '\n';
}
signed main(){
    init();
    solve();
}