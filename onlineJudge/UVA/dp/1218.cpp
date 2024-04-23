#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 1e5 + 5;
vector<int> son[maxn];
int n, d[maxn][3], t, vis[maxn];
void init(){
    for (int i = 1; i <= n;i++){
        son[i].clear();
        vis[i] = 0;
        for (int j = 0; j < 3;j++){
            d[i][j] = inf;
        }
    }
}
// d[u][0] = min(d[v][1]) d[u][1] = min(d[v][2]) d[u][2] = sum(d[v][2])+min(d[v][0] - d[v][2])
void dfs(int fa,int u){
    // if(son[u].size() == 1 && u != 1){
    //     d[u][0] = 1;
    //     d[u][1] = 0;
    //     return;
    // }
    d[u][0] = 1;
    d[u][1] = 0;
    int l = son[u].size();
    long long sum = 0;
    for (int i = 0; i < l;i++){
        int v = son[u][i];
        if(v == fa)
            continue;
        dfs(u,v);
        d[u][0] += min(d[v][0], d[v][1]);
        d[u][1] += d[v][2];
        d[u][2] = min(d[v][0] - d[v][2], d[u][2]);
    }
    d[u][2] += d[u][1];
    // cout << u << ' ' << d[u][0] << ' ' << d[u][1] << ' ' << d[u][2] << '\n';
}
int main(){
    while(cin >> n){
        init();
        for (int i = 0; i < n - 1;i++){
            int u, v;
            cin >> u >> v;
            son[u].push_back(v);
            son[v].push_back(u);
        }
        dfs(0, 1);
        cout << min(d[1][0], d[1][2]) << '\n';
        cin >> n;
        if(n == -1)
            break;
    }
    return 0;
}