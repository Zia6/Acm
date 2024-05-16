#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define int long long
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;
struct Edge{
    int u,v,flow,cap;
    Edge(int u,int v,int flow,int cap):u(u),v(v),flow(flow),cap(cap){}
};

struct EdmondsKarp{
    int n,m;
    std:: vector<Edge> edges;
    std:: vector<int> G[maxn];
    int a[maxn],p[maxn];

    void init(int n){
        for(int i = 0;i < n;i++){
            G[i].clear();
        }
        edges.clear();
    }

    void addEdge(int u,int v,int cap){
        edges.push_back(Edge(u,v,0,cap));
        edges.push_back(Edge(v,u,0,0));
        m = edges.size();
        G[u].push_back(m-2);
        G[v].push_back(m-1);
    }

    int Maxflow(int s,int t){
        int flow = 0;
        while(1){
            memset(a,0,sizeof(a));
            std:: queue<int> Q;
            Q.push(s);
            a[s] = inf;
            while(!Q.empty()){
                int x = Q.front();
                Q.pop();
                for(int i = 0;i < G[x].size();i++){
                    Edge& e = edges[G[x][i]];
                    if(!a[e.v] && e.cap > e.flow){
                        p[e.v] = G[x][i];
                        a[e.v] = std::min(a[x],e.cap - e.flow);
                        Q.push(e.v);
                    }
                }
                if(a[t]) break;
            }
            if(!a[t]) break;
            for(int u = t;u != s;u = edges[p[u]].u){
                edges[p[u]].flow += a[t];
                edges[p[u]^1].flow -= a[t];
            }
            flow += a[t];
        }
        return flow;
    }
};
signed main(){
    struct EdmondsKarp ek;
    int n,m,s,t;
    std :: cin >> n >> m >> s >> t;
    for(int i = 0;i < m;i++){
        int u,v,cap;
        std :: cin >> u >> v >> cap;
        ek.addEdge(u,v,cap);
    }
    std :: cout << ek.Maxflow(s,t) << '\n';
}