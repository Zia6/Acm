#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
#define int long long
const int maxn = 2e5 + 5, inf =  0x3f3f3f3f3f3f3f3f;
int cnt = 0;
int n, m, qq;
struct edge {
    int to, nex, w, x;
} e[maxn << 1]; // 注意这里的边数翻倍，因为是双向添加
int head[maxn], v1[maxn], v2[maxn], a[maxn], vis[maxn];

void add(int u, int v, int w, int x) {
    e[++cnt] = {v, head[u], w, x};
    head[u] = cnt;
}
multiset<int> mul;
void bfs(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &q, int *vv, int x) {
    while (!q.empty()) {
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; ~i; i = e[i].nex) {
            if (e[i].x != x) continue;
            int v = e[i].to;
            if (!vis[v]&&vv[v] > d + e[i].w) {
                vv[v] = d + e[i].w;
                q.push({vv[v], v});
            }
        }
    }
}

signed main() {
    cin >> n >> m >> qq;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        add(u, v, c, 0);
        add(v, u, d, 1);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // BFS for v1
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) v1[i] = inf;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    v1[1] = 0;
    bfs(q, v1, 0);

    // BFS for v2
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) v2[i] = inf;
    q.push({0, n});
    v2[n] = 0;
    bfs(q, v2, 1);
    for (int i = 1; i <= n; i++) {
        if(v1[i]!=inf && v2[i]!=inf)
        mul.insert(v1[i] + (v2[i] + a[i] - 1)/a[i]);
    }

    while (qq--) {
        int xx, aa;
        cin >> xx >> aa;
        int tem1 = v1[xx] + (v2[xx] + aa - 1) / aa;
        int tem2 = v1[xx] + (v2[xx] + a[xx] - 1) / a[xx];
        auto it = mul.find(tem2);
        mul.erase(it);
        mul.insert(tem1);
        cout << *mul.begin() << '\n';
        a[xx] = aa;
    }
}
