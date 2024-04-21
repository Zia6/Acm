#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 1e3+5;
struct vec{
    int x;
    int y;
    double red;
    int color;
    int operator ^ (const vec& v) const {
        return x * v.y - y * v.x;
    }
    bool operator < (const vec &v) const{
        return red < v.red;
    }
}v1[maxn],v2[maxn];
int n = 0,ans = 0;
void solve(int x){
    int k = 0,cnt = 2;
    for(int i = 0; i < n; i++){
        if(x == i) continue;
        v2[k].x = v1[i].x - v1[x].x;
        v2[k].y = v1[i].y - v1[x].y;
        if(v1[i].color){
            v2[k].x = -v2[k].x;
            v2[k].y = -v2[k].y;
        }
        v2[k].red = atan2(v2[k].y,v2[k].x);
        k++;
    }
    sort(v2,v2 + k);
    int l = 0 ,r = 0;
    while(l < k){
        if( l == r) r = (r + 1) % k , cnt++;
        while(l != r && (v2[l] ^ v2[r]) >= 0){
            r = (r + 1) % k;
            cnt++;
        }
        cnt--;
        ans = max(ans,cnt);
        l++;
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF && n){
        for(int i = 0 ;i < n ;i++){
            scanf("%d %d %d",&v1[i].x,&v1[i].y,&v1[i].color);
        }
        for(int i = 0; i < n; i++){
            solve(i);
        }
            printf("%d\n",ans);
            ans = 0;
    }

}
