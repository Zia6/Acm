#include<iostream>
#include<set>
#include<map>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
map<int, int> mp;
int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    long long ans = 0;
    int r = 0;
    if(k == 1){
        cout << n << '\n';
        return 0;
    }
    int cnt = 0;
    for (int l = 0; l < n;l++){
        while(r < n && (mp[a[r]] || cnt < k)){
            mp[a[r]]++;
            if(mp[a[r]] == 1){
                cnt++;
            }
            r++;
        }
        mp[a[l]]--;
        if(mp[a[l]] == 0)
            cnt--;
        ans += r - l;
    }
        cout << ans << '\n';
}