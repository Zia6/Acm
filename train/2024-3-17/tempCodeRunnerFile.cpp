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
ll bit_pow(ll a,ll b,ll mod){
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
    int a, b, c;
    cin>>a>>b>>c;
    cout << bit_pow(a, bit_pow(b,c,mod-2),mod) << '\n';
}
signed main(){
    int T;
    cin >> T;
    while(T--)
    solve();
}