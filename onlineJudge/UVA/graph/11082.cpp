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
struct Edge{
    int u,v,flow,cap;
    Edge(int u,int v,int flow,int cap):u(u),v(v),flow(flow),cap(cap){}
};

struct EdmondsKarp{
    int n,m;
    std::vector<Edge> edges;
    std::vector<int> G[maxn];
    int a[maxn],p[maxn];

    void init(int n){
        for(int i = 0; i < n; i++){
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
}ek;
int R,C;
int prer[maxn],prec[maxn],row[maxn],col[maxn];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T,cnt = 0;
    std:: cin >> T;
    while(T--){
        std:: cin >> R >> C;
        for(int i = 1;i <= R;i++){
            std:: cin >> prer[i];
            row[i] = prer[i] - prer[i - 1];
        }
        for(int i = 1;i <= C;i++){
            std:: cin >> prec[i];
            col[i] = prec[i] - prec[i - 1]; 
        }
        ek.init(R + C + 2);
        int s = 0,t = C + R + 1;
        for(int i = 1;i <= R;i++){
            for(int j = 1;j <= C;j++){
                ek.addEdge(i,j + R,19);
            }
        }
        for(int i = 1;i <= R;i++){
            ek.addEdge(s,i,row[i] - C);
        }
        for(int i = 1;i <= C;i++){
            ek.addEdge(i + R,t,col[i] - R);
        }
        ek.Maxflow(s,t);
        std:: cout << "Matrix " << ++cnt << '\n' ;
        for(int i = 1;i <= R * C;i++){
            if(i % C == 0) std:: cout << ek.edges[(i - 1) * 2].flow + 1 << '\n';
            else std:: cout << ek.edges[(i - 1) * 2].flow + 1<< ' ';
        }
        if(T) std:: cout << '\n';
    }
    return 0;
}