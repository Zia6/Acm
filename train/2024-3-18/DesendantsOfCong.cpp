#include <vector>
#include <iostream>
using namespace std;
#define lc o << 1
#define rc o << 1 | 1

using i64 = long long;
const int maxn = 1e5;
int n, q;
vector<int> son[maxn + 10];

int dep[maxn + 10];
vector<int> vec[maxn + 10];
struct Q {
    int id, u, val;
};
vector<Q> qry[maxn + 10];
int tot, in[maxn + 10], out[maxn + 10];
void dfs(int u, int fno) {
    in[u] = ++tot;
    dep[u] = dep[fno] + 1;
    vec[ dep[u] ].push_back(u);

    for (int v : son[u]) {
        dfs(v, u);
    }
    out[u] = tot;
}

i64 ans[maxn + 10];
i64 d[4 * maxn + 10], tag[4 * maxn + 10];
void pd(int o, int l, int r, int mid) {
    d[lc] += 1ll * (mid - l + 1) * tag[o];
    tag[lc] += tag[o];
    d[rc] += 1ll * (r - mid) * tag[o];
    tag[rc] += tag[o];
    tag[o] = 0;
}
void upd(int o, int l, int r, int s, int t, int val) {
    if (s <= l && r <= t) {
        d[o] += 1ll * (r - l + 1) * val;
        tag[o] += val;
        return ;
    }
    int mid = l + r >> 1;
    if (tag[o]) {
        pd(o, l, r, mid);
    }
    if (s <= mid) upd(lc, l, mid, s, t, val);
    if (t > mid) upd(rc, mid + 1, r, s, t, val);
    d[o] = d[lc] + d[rc];
}

i64 getsum(int o, int l, int r, int s, int t) {
    if (s <= l && r <= t) {
        return d[o];
    }
    int mid = l + r >> 1;
    i64 res = 0;
    if (tag[o]) {
        pd(o, l, r, mid);
    }
    if (s <= mid) res += getsum(lc, l, mid, s, t);
    if (t > mid) res += getsum(rc, mid + 1, r, s, t);
    return res;
}
void solve() {
    cin >> n >> q;

    tot = 0;
    for (int i = 0; i <= n; i++) {
        dep[i] = 0;
        son[i].clear();
        vec[i].clear();
        qry[i].clear();
    }
    for (int i = 0; i <= q; i++) ans[i] = 0;
    for (int u = 2; u <= n; u++) {
        int v; cin >> v;
        son[v].push_back(u);
    }

    dfs(1, 0);
    for (int i = 0; i <= n; i++) {
        son[i].clear();
    }

    for (int i = 1; i <= q; i++) {
        int u, k, val; cin >> u >> k >> val;
        if (dep[u] + k > n) {
            continue;
        }
        qry[ dep[u] + k ].push_back({i, u, val});
    }

    for (int i = 0; i <= n; i++) {
        int _n = (int)vec[i].size();
        if (_n == 0) {
            qry[i].clear();
            continue;
        }
        //d.resize(4 * _n + 5, 0);
        //tag.resize(4 * _n + 5, 0);
        for (Q tmp : qry[i]) {
            int L, R;

            int u = vec[i][0];
            if (out[tmp.u] < in[u]) continue;

            u = vec[i][(int)vec[i].size() - 1];
            if (out[u] < in[tmp.u]) continue;

            int l = 1, r = _n;
            while (l < r) {
                int mid = l + r >> 1;
                int u = vec[i][mid - 1];
                if (in[u] < in[tmp.u]) l = mid + 1;
                else r = mid;
            }
            L = l;

            l = 1, r = _n + 1;
            while (l < r) {
                int mid = l + r >> 1;
                int u = vec[i][mid - 1];
                if (in[u] <= out[tmp.u]) l = mid + 1;
                else r = mid;
            }
            R = l - 1;
            upd(1, 1, _n, L, R, tmp.val);
            ans[ tmp.id ] = getsum(1, 1, _n, L, R);
        }

        vec[i].clear();
        qry[i].clear();

        for (int i = 0; i <= 4 * _n + 5; i++) {
            d[i] = tag[i] = 0;
        }
        //d.clear();
        //tag.clear();
    }

    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T = 1; cin >> T;
    while (T--)
        solve();

    return 0;
}