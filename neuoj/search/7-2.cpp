#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
long long pre[maxn];
map<long long, long long> mp;

int main(){
    int n, x;
    cin >> n >> x;
    long long ans = 0;
    mp.insert({0, 1});
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        pre[i] = a[i] + pre[i - 1];
        if(mp.count(pre[i] - x)){
            ans += mp[pre[i] - x];
        }
        mp[pre[i]]++;
    }
    cout << ans << '\n';
}
