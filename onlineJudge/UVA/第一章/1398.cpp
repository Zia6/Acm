#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<iomanip>
#include<sstream>
using ll = long long;
const long long inf= 1e18;
const int maxn = 1e5 + 5;
template<class T>
inline void read(T& x) {
    x = 0;
    int f = 1;
    char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    x *= f;
}
struct point{
    long long value;
    int x;
    bool operator < (const point& p)const {
        return value == p.value ? x < p.x : value < p.value;
    }
};
long long gcd(long long x,long long y){
    return y == 0 ? x : gcd(y,x % y);
}

void update(ll x,ll a,ll w,ll& l,ll& r){
    if(a == 0){
        if(x <= 0 || x >= w){
            r = l - 1;
        }
    }else if(a > 0){
        l = std::max((-x) / a,l);
        r = std::min((w - x) / a,r);
    }else {
        l = std:: max((w - x) / a,l);
        r = std:: min((-x) / a,r);
    }
}
point p[maxn << 1];
void solve(){
    int w,h,n,cnt = 0;
    read(w),read(h),read(n);
    std::vector<ll> vx(n),vy(n),sx(n),sy(n);
    for(int i = 0;i < n;i++){
        read(sx[i]),read(sy[i]),read(vx[i]),read(vy[i]);
    }
    ll lx = 1,ly = 1;
    // for(int i = 0;i < n;i++){
    //     if(vx[i]) lx = lx * vx[i] / gcd(lx,vx[i]);
    //     if(vy[i]) ly = ly * vy[i] / gcd(ly,vy[i]);
    // }
    lx = ly = 2520;
    w *= lx,h *= ly;
    for(int i = 0;i < n;i++){
        sx[i] *= lx;
        sy[i] *= ly;
    }
    for(int i = 0;i < n;i++){
        long long l = 0,r = inf;
        update(sx[i],vx[i],w,l,r);
        update(sy[i],vy[i],h,l,r);
        if(l >= r) continue;
        p[cnt++] = (point){l,1};
        p[cnt++] = (point){r,0};
        // std:: cout << 1 << ' ' << l << ' ' << r << '\n';
    }
    std::sort(p,p + cnt);
    int tem = 0,ans = 0;
    for(int i = 0;i < cnt;i++){
        // std:: cout << 2 << ' ' << p[i].value << ' ' << p[i].x << '\n';
        if(p[i].x > 0){
            tem++;
            ans = std::max(ans,tem);
        }else tem--;
    }
    std:: cout << ans << '\n';
}

int main() {
    int T;
    read(T);
    while(T--){
        solve();
    }
    return 0;
}