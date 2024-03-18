#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
const int N = 1e5 + 100;
using ll = long long;

struct Node {
    ll sum, lazy;
    Node *left, *right;

    Node() : sum(0), lazy(0), left(nullptr), right(nullptr) {}
};

map<int, Node*> tree; // 使用map管理每个深度的线段树根节点

void pushup(Node* node) {
    node->sum = (node->left ? node->left->sum : 0) + (node->right ? node->right->sum : 0);
}

void pushdown(Node* node, int l, int r) {
    if (node->lazy) {
        int mid = (l + r) / 2;
        if (!node->left) node->left = new Node();
        if (!node->right) node->right = new Node();

        ll &lazy = node->lazy;
        node->left->sum += (mid - l + 1) * lazy;
        node->left->lazy += lazy;
        node->right->sum += (r - mid) * lazy;
        node->right->lazy += lazy;

        lazy = 0;
    }
}

void update(Node*& node, int l, int r, int L, int R, ll val) {
    if (!node) node = new Node();
    if (L <= l && r <= R) {
        node->sum += (r - l + 1) * val;
        node->lazy += val;
        return;
    }

    pushdown(node, l, r);

    int mid = (l + r) / 2;
    if (L <= mid) update(node->left, l, mid, L, R, val);
    if (R > mid) update(node->right, mid + 1, r, L, R, val);

    pushup(node);
}

ll query(Node* node, int l, int r, int L, int R) {
    if (!node || L > r || R < l) return 0;
    if (L <= l && r <= R) return node->sum;

    pushdown(node, l, r);

    int mid = (l + r) / 2;
    ll sum = 0;
    if (L <= mid) sum += query(node->left, l, mid, L, R);
    if (R > mid) sum += query(node->right, mid + 1, r, L, R);
    return sum;
}
void cleanup(Node* node) {
    if (!node) return; // 如果节点为空，直接返回

    cleanup(node->left); // 递归清理左子树
    cleanup(node->right); // 递归清理右子树

    delete node; // 删除当前节点
}

struct edge{
    int to,next;
}e[N];
int head[N],cnt=0;
int in[N], out[N], deep[N];
vector<int> v[N]; //存储每个深度的点
void add(int u,int v){
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
void init(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int tot = 0;
int maxdept=0;
void dfs(int now,int fa){
    // cout << now << '\n';
    in[now] = ++tot;
    // cout << in[now] << '\n';
    deep[now] = deep[fa] + 1;
    maxdept=max(maxdept,deep[now]);
    // cout << deep[now] << '\n';
    v[deep[now]].push_back(now);
    for (int i = head[now]; i != -1;i=e[i].next){
        if(e[i].to==fa)
            continue;
        dfs(e[i].to, now);
    }
    out[now] = tot;
}
void init2(){
    // cout<<"init2\n";
    cnt = 0;
    for (int i = 0; i < N;i++){
        v[i].resize(0);
    }
    memset(in, 0, sizeof in);
    memset(head,-1,sizeof head);
    memset(deep,0,sizeof deep);
    memset(out,0,sizeof out);
    tot = 0;
    maxdept=0;
}
bool cmp(int a,int b){
    return in[a] < in[b];
}
void solve(){
    // cout << "solve\n";
    init2();
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n;i++){
        int t;
        cin >> t;
        add(t, i);
    }
    // cout<<"start"<<'\n';
    dfs(1, 0);
    // cout<<"end"<<'\n';
    int u, k;
    ll w;
    // for (int i = 1; i <= maxdept;i++){
    //     sort(v[i].begin(), v[i].end(),cmp);
    // }
        while (m--)
        {
            cin >> u >> k >> w;
            int d = deep[u] + k;
            if (d <= 0 || d > N - 1 || v[d].size() == 0)
            {
                cout << "0\n";
                continue;
            }
            int l = 0, r = v[d].size() - 1;
            int s, t;
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (in[u] <= in[v[d][mid]])
                    r = mid;
                else
                    l = mid + 1;
            }
            s = l;
            r = v[d].size() - 1;
            while (l < r)
            {
                int mid = (l + r + 1) >> 1;
                if (out[u] >= out[v[d][mid]])
                    l = mid;
                else
                    r = mid - 1;
            }
            t = l;
            update(tree[d], 1, v[d].size(), s + 1, t + 1, w);
            cout << query(tree[d], 1, v[d].size(), s + 1, t + 1) << '\n';
        }
    for(int i=1;i<=maxdept;i++) {
        cleanup(tree[i]);
        tree[i]=NULL;
    }
    tree.clear();
}
signed main(){
    init();
    int T;
    cin >> T;
    while(T--)
    solve();
}