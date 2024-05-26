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
    #define int long long
    const int maxn = 2e5 + 5;
    const int inf = 0x3f3f3f3f;

    int a[maxn],ll[maxn],rr[maxn];
    bool check(int m,int n){
        int x= a[0], y = m - a[0];
        ll[0] = x,rr[0] = 0;
        for(int i = 1;i < n;i++){
            if((i & 1)){
                ll[i] = std:: min(x - ll[i - 1],a[i]);
                rr[i] = a[i] - ll[i];
            }else {
                rr[i] = std:: min(y - rr[i - 1],a[i]);
                ll[i] = a[i] - rr[i];
            }
        }
        return ll[n - 1] == 0;
    }

    signed main() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        int n;
        while(std:: cin >> n && n){
            int ans = 0, l = 0 , r = inf;
            for(int i = 0;i < n;i++){
                std:: cin >> a[i];
            }
            a[n] = a[0];
            for(int i = 0;i < n;i++){
                l = std:: max(a[i] + a[(i + 1)], l);
            }
            if(!(n & 1)){
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