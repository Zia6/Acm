#include<cstdio>
#include<climits>
#include<cmath>
#include<iostream>
using namespace std;
#define int long long
const int maxn = 2e5 + 5;
const int inf = LONG_LONG_MAX;
int a[maxn], n, t;
bool check(int x){
    int res = 0;
    for (int i = 0; i < n;i++){
        res += x / a[i];
        if(res >= t)
            return true;
    }
    return res >= t;
}
signed main(){
    int l = 0, r = LONG_LONG_MAX;
    scanf("%lld %lld", &n, &t);
    for (int i = 0; i < n;i++){
        scanf("%lld", a + i);
    }
    int mid;
    while(l < r){
        mid = l + ((r - l) >> 1);
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%lld\n", l);
}