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
using ull = unsigned long long;

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
const int maxn = 252 * 252;
const int inf = 0x3f3f3f3f;
void solve(){
    int n,p,q;
    read(n),read(p),read(q);
    p++,q++;
    std::vector<int> v1(p),v2(q),vis(n * n + 1),mp(n * n + 1),v,d;
    int cnt = 0;
    for(int i = 0;i < p;i++){
        read(v1[i]);
        if(!vis[v1[i]]){
            mp[v1[i]] = ++cnt; 
            vis[v1[i]] = 1; 
        } 
    }
    for(int i = 0;i < q;i++){
        read(v2[i]);
        if(!vis[v2[i]]) continue;
        else {
            v.push_back(mp[v2[i]]);
        }
    }
    d.resize(v.size() + 1,inf);
    d[0] = -1;
    int l = v.size();
    int ans = 0;
    for(int i = 0;i < l;i++){
        // std:: cout << v[i] << ' ';
        int it = std::upper_bound(d.begin(),d.end(),v[i]) - d.begin();
        ans = std::max(ans,it);
        d[it] = v[i];
    }
    std:: cout << ans << '\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T,cnt = 0;
    read(T);
    while(T--){
        std:: cout << "Case " << ++cnt << ": " ;
        solve();
    }
    return 0;
}