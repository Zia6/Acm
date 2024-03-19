#include<iostream>
using namespace std;
#define int long long
using ll = long long;
const int N = 6e5 + 5;

struct segtree{
    ll lazy[N << 2],sum[N << 2];
    void pushup(int rt){
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }
    void pushdown(int rt,int l,int r){
        if(lazy[rt]){
            int mid = (l + r) >> 1;
            sum[rt << 1] += lazy[rt] * (mid - l + 1);
            sum[rt << 1 | 1] += lazy[rt] * (r - mid);
            lazy[rt << 1] += lazy[rt];
            lazy[rt << 1 | 1] += lazy[rt];
            lazy[rt] = 0;
        }
    }
    void build(int rt,int l,int r){
        if(l == r){
            sum[rt] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(rt << 1,l,mid);
        build(rt << 1 | 1,mid + 1,r);
        pushup(rt);
    }
    void update(int rt,int l,int r,int L,int R,int v){
        if(L <= l && r <= R){
            sum[rt] = (r - l + 1) * v;
            lazy[rt] = v;
            return;
        }
        pushdown(rt,l,r);
        int mid = (l + r) >> 1;
        if(L <= mid)
            update(rt << 1,l,mid,L,R,v);
        if(R > mid)
            update(rt << 1 | 1,mid + 1,r,L,R,v);
        pushup(rt);
    }
    ll query(int rt,int l,int r,int L,int R){
        if(L <= l && r <= R)
            return sum[rt];
        pushdown(rt,l,r);
        int mid = (l + r) >> 1;
        ll ans = 0;
        if(L <= mid)
            ans += query(rt << 1,l,mid,L,R);
        if(R > mid)
            ans += query(rt << 1 | 1,mid + 1,r,L,R);
        return ans;
    } 
}tr;

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void solve(){
    int n, m;
    cin >> n >> m;

    tr.build(1,1,n);
    for (int i = 1; i <= n;i++){
        int t;
        cin >> t;
        tr.update(1,1,n,i,i,t);
    }
    int op, i, x;
    while(m--){
        long long ans = 0, l, r = 0, cnt = 0;
        cin >> op>>i >> x;
        if(op == 1){
            tr.update(1,1,n,i+1,i+1,x);
        }else if(op == 2){
            if((x^i)+1<=n)
                ans = tr.query(1,1,n,(x^i)+1,(x^i)+1);
            else
                ans = 0;
            for (int j = 31; j >= 0;j--){
                if(x & (1 << j)){
                    cnt = i >> j << j;
                    l = 1;
                    r=l+(1<<j)-1;
                    if(l+cnt>n)
                        continue;
                    ans += tr.query(1,1,n,l+cnt,min(r+cnt,n));
                    i ^= (1 << j);
                    // cout <<j<<' '<< cnt<<' '<<l<<' '<<r<<' '<<ans << '\n';
                }
            }
            // cout << 1 << " ";
            cout << ans << '\n';
        }
    }
}
signed main(){
    init();
    solve();
}