#include<cstdio>
#include<climits>
using namespace std;
#define int long long
const int maxn = 2e5 + 5;
const int inf = __LONG_LONG_MAX__;
int a[maxn], n, t;
bool check(int x){
    int res = 0;
    for (int i = 0; i < n;i++){
        res += x / a[i];
    }
    return res >= t;
}
signed main(){

    scanf("%d %d", &n, &t);
    for (int i = 0; i < n;i++){
        scanf("%d", a + i);
    }
    int l = 1, r = inf, mid;
    while(l < r){
        mid = l + ((r - l) >> 1);
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", l);
}