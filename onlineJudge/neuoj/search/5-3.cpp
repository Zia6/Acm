#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define int long long
const int maxn = 1e3 + 5;
pair<int, int> v[maxn * maxn];
int getIndex(int x,int y){
    return (x << 16) | y;
}
int getI(int x){
    return x >> 16;
}
int getJ(int x){
    return x & ((1 << 16) - 1);
}
int a[maxn];
signed main(){
    int n, k, cnt = 0;
    scanf("%lld %lld", &n, &k);
    for (int i = 1; i <= n;i++){
        scanf("%lld", a + i);
    }
    for (int i = 1; i <= n;i++){
        for (int j = i + 1; j <= n;j++){
            v[cnt++].first = a[i] + a[j];
            v[cnt - 1].second = getIndex(i, j);
        }
    }
    sort(v, v + cnt);
    for (int i = 1; i <= n;i++){
        for (int j = i + 1; j <= n;j++){
            int w = k - a[i] - a[j];
            int l = 0, r = cnt - 1, mid;
            while(l < r){
                mid = l + ((r - l) >> 1);
                if(v[mid].first >= w)
                    r = mid;
                else
                    l = mid + 1;
            }
            if(v[l].first != w)
                continue;
            while(l < cnt && v[l].first == w && (getI(v[l].second) == i || getJ(v[l].second) == j||getI(v[l].second) == j || getJ(v[l].second) == i)){
                l++;
            }
            if(l < cnt && v[l].first == w && getI(v[l].second) != i && getJ(v[l].second) != j&&getI(v[l].second) != j && getJ(v[l].second) != i){
                printf("%lld %lld %lld %lld", i, j, getI(v[l].second), getJ(v[l].second));
                return 0;
            }
        }
    }
    printf("IMPOSSIBLE");
}