#include<iostream>
#include<cstring>
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
#include<iomanip>
template<class T>
inline void read(T& x) {
    x = 0;
    int f = 1;
    char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    x *= f;
}

int main() {
    int n,m;
    while(std:: cin >> n >> m){
        double ans = 0;
        for(int i = 1;i < n;i++){
            double pos = 1.0 * i / n * (n + m);
            ans += (fabs(pos - floor(pos + 0.5))) / (n + m) * 1e4;
        }
        printf("%.4lf\n",ans);
    }
    return 0;
}