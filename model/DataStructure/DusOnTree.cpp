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
const int maxn = 1e5 + 5;
struct edge{
    int to;
    int nex;
}e[maxn << 1];
int head[maxn],L[maxn],R[maxn],count[maxn],totcolor = 0,cnt = 0,dfn[maxn],big[maxn],tot = 0,sz[maxn],c[maxn];
ll ans[maxn];
void add_edge(int u,int v){
    e[cnt].to = v;
    e[cnt].nex = head[u];
    head[u] = cnt++;
}

void dfs(int u,int fa){
    L[u] = ++tot;
    dfn[tot] = u;
    sz[u] = 1;
    for(int i = head[u];~i;i = e[i].nex){
        int v = e[i].to;
        if(v == fa) continue;
        dfs(v,u);
        sz[u] += sz[v];
        if(!big[u] || sz[v] > sz[big[u]]) big[u] = v;
    }
    R[u] = tot;
}

void add(int x){
    count[x]++;
    if(count[x] == 1) totcolor++;
}
void del(int x){
    count[x]--;
    if(count[x] == 0) totcolor--;
}

void dsu(int u,int fa){
    for(int i = head[u];~i;i = e[i].nex){
        int v = e[i].to;
        if(v == fa || v == big[u]) continue;
        dsu(v,u);
        for(int j = L[v];j <= R[v];j++){
            del(c[dfn[j]]);
        }
    }
    if(big[u]) dsu(big[u],u);
    add(c[u]);
    for(int i = head[u];~i;i = e[i].nex){
        int v = e[i].to;
        if(v == fa || v == big[u]) continue;
        for(int j = L[v];j <= R[v];j++){
            add(c[dfn[j]]);
        }
    }
    ans[u] = totcolor;
}


void solve(){
    memset(head,-1,sizeof(head));
    int n;
    read(n);
    for(int i = 0;i < n - 1;i++){
        int u,v;
        read(u),read(v);
        add_edge(u,v);
        add_edge(v,u);
    }
    for(int i = 1;i <= n;i++) read(c[i]);
    dfs(1,0);
    dsu(1,0);
    int k;
    read(k);
    while(k--){
        int x;
        read(x);
        std::cout << ans[x] << '\n';
    }
}


int main() {
    solve();
    return 0;
}