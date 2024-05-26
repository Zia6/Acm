    #include<iostream>
    #include<cstdio>
    #include<vector>
    #include<queue>
    #include<stack>
    #include<map>
    #include<set>
    #include<algorithm>
    #include<cmath>
    #include<cctype>
    #include<iomanip>
    #include<sstream>
    #include<cstring>
    const int maxn = 1e5 + 5;
    const int inf = 0x3f3f3f3f;

    int a[maxn],ll[maxn],rr[maxn];
    bool check(int m,int n){
        int x = a[0], y = m - a[0];
        ll[0] = x,rr[0] = 0;
        for(int i = 1;i < n;i++){
            if(i % 2){
                ll[i] = std:: min(x - ll[i - 1],a[i]);
                rr[i] = a[i] - ll[i];
            }else {
                rr[i] = std:: min(y - rr[i - 1],a[i]);
                ll[i] = a[i] - rr[i];
            }
        }
        return ll[n - 1] == 0;
    }

    int main() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        int n;
        while(std:: cin >> n && n){
            memset(a,0,sizeof(a));
            memset(ll,0,sizeof(ll));
            memset(rr,0,sizeof(rr));
            int ans = 0, l = 0 , r = 0;
            for(int i = 0;i < n;i++){
                std:: cin >> a[i];
            }
            if(n == 1){
                std:: cout << a[0] << '\n';
                continue;
            }
            a[n] = a[0];
            for(int i = 0;i < n;i++){
                l = std:: max(a[i] + a[(i + 1)], l);
                r = std:: max(a[i] * 3,r);
            }
            if(n % 2 == 0){
                ans = l;
            }else {
                while(l < r){
                    int mid = l + ((r - l) >> 1);
                    if(check(mid,n)) r = mid;
                    else l = mid + 1;
                }
                ans = l;
            }
            std:: cout << ans << '\n';
        }
        return 0;
    }