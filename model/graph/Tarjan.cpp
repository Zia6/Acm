#include<iostream>
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
#include<cstring>
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
struct edge{
    int v;
    int nex;
}e[maxn];
int head[maxn], cnt;
int dfn[maxn], low[maxn], scc[maxn], in[maxn], out[maxn], scc_cnt, dfn_cnt;
int sz[maxn];
std::stack<int> s;

void add_edge(int u, int v){
    e[cnt].v = v;
    e[cnt].nex = head[u];
    head[u] = cnt++;
}

void tarjan(int u){
    dfn[u] = low[u] = ++dfn_cnt;
    s.push(u);
    for(int i = head[u]; ~i; i = e[i].nex){
        int v = e[i].v;
        if(!dfn[v]){
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        }else if(!scc[v]){
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]){
        scc_cnt++;
        while(1){
            int x = s.top();
            s.pop();
            scc[x] = scc_cnt;
            sz[scc_cnt]++;
            if(x == u) break;
        }
    }
}
