#include<iostream>
#include<set>
using namespace std;
const int maxn = 2e5 + 5;
long long pre[maxn];
multiset<long long> s;
// max pre[k] - pre[k - l]  pre[k] - pre[k - r]
// pre[k + 1] - pre[k + 1 - l] pre[k + 1] - pre[k + 1 - r]
int main(){
    int n, l, r, t;
    cin >> n >> l >> r;
    long long ans = -0xffffffffffffff;
    for (int i = 1; i <= n;i++){
        cin >> t;
        pre[i] = pre[i - 1] + t;
    }
    for (int i = l; i <= n;i++){
        if(i > r){
            auto it = s.find(pre[i - r - 1]);
            s.erase(it);
        }
        s.insert(pre[i - l]);
        ans = max(ans, pre[i] - *s.begin());
    }
    cout << ans << '\n';
}