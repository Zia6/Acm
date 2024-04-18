#include<iostream>
#include<map>
using namespace std;
const int maxn = 1e3 + 5;
using ll = long long;
using ull = unsigned long long;
ll bit_pow(ull a,ull b,ull mod){
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
long long f[maxn * maxn];
signed main(){
    unsigned long long a,b;
    int T,n;
    cin >> T;
    while(T--){
        cin >> a >> b >> n;
        int M;
        f[0] = 0;
        f[1] = 1ll;
        if(n == 1){
            cout << 0 << '\n';
            continue;
        }
        for(int i = 2;i <= n * n;i++){
            f[i] = (f[i - 1] + f[i - 2]) % n;
            if(f[i] == 1 && f[i - 1] == 0){
                M = i - 1;
                break;
            }
        }
        cout << f[bit_pow(a % M,b,M)] << '\n';
    }
}