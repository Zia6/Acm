#include<iostream>
using namespace std;
using ll = long long;
ll bit_pow(ll a,ll b,ll mod){
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}