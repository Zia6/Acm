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
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;
struct Edge{
    int u,v,flow,cap;
    Edge(int u,int v,int flow,int cap):u(u),v(v),flow(flow),cap(cap){}
};
std ::vector<int> ans;
int a[maxn],p[maxn];
struct EdmondsKarp{
    int n,m;
    std::vector<Edge> edges;
    std::vector<int> G[maxn];
    void init(){
        for(int i = 0; i < maxn; i++){
            G[i].clear();
        }
        edges.clear();
    }

    void addEdge(int u, int v, int cap){
        edges.push_back(Edge(u, v, 0, cap));
        edges.push_back(Edge(v, u, 0, 0));
        m = edges.size();
        G[u].push_back(m-2);
        G[v].push_back(m-1);
    }

    int Maxflow(int s, int t){
        int flow = 0;
        while(1){
            memset(a, 0, sizeof(a));
            std::queue<int> Q;
            Q.push(s);
            a[s] = inf; // Define 'inf' in your actual usage or replace with INT_MAX
            while(!Q.empty()){
                int x = Q.front();
                Q.pop();
                for(int i = 0; i < G[x].size(); i++){
                    Edge& e = edges[G[x][i]];
                    if(!a[e.v] && e.cap > e.flow){
                        p[e.v] = G[x][i];
                        a[e.v] = std::min(a[x], e.cap - e.flow);
                        Q.push(e.v);
                    }
                }
                if(a[t]) break;
            }
            if(!a[t]) break;
            for(int u = t; u != s; u = edges[p[u]].u){
                edges[p[u]].flow += a[t];
                edges[p[u]^1].flow -= a[t];
            }
            flow += a[t];
        }
        return flow;
    }
};
void solve(){
    std:: vector<int> device;
    std:: map<std::string,int> mp;
    std:: vector<int> target;
    int n,m,k,cnt = 2;
    std:: cin >> n;
    std:: string s,s1,s2;
    EdmondsKarp ek;
    ek.init();
    for(int i = 0;i < n;i++){
        std:: cin >> s;
        if(mp.count(s) == 0){
            mp[s] = cnt++;
        }
        ek.addEdge(mp[s],1,1);
        target.push_back(mp[s]);
    }
    std:: cin >> m;
    for(int i = 0;i < m;i++){
        std:: cin >> s1 >> s2;
        if(mp.count(s1) == 0){
            mp[s1] = cnt++;
        }
        if(mp.count(s2) == 0){
            mp[s2] = cnt++;
        }
        ek.addEdge(mp[s1],mp[s2],inf);
        ek.addEdge(0,mp[s1],1);
    }
    std:: cin >> k;
    for(int i = 0;i < k;i++){
        std:: cin >> s1 >> s2;
        ek.addEdge(mp[s1],mp[s2],inf);
    }
    ans.push_back(m - ek.Maxflow(0,1));
}
int main() {
    int T;
    std:: cin >> T;
    while(T--){
        solve();
    }
    for(int i = 0;i < ans.size();i++){
        std:: cout << ans[i] << '\n';
        if(i < ans.size() - 1) std:: cout << '\n';
    }
    return 0;
}