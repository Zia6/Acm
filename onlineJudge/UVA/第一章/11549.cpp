#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <sstream>

template <class T>
inline void read(T &x)
{
    x = 0;
    int f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    x *= f;
}


int n,k,m;
long long nex(long long x){
    return x * x % m;
}
int main()
{
    // Your code here
    int T;
    std::cin >> T;
    while (T--)
    {

        read(n);
        read(k);
        m = 1;
        for(int i = 0;i < n;i++){
            m *= 10;
        }
        long long ans = k;
        long long k1 = k,k2 = k;
        do{
            k1 = nex(k1);
            ans = std:: max(k1,ans);
            k2 = nex(k2);
            ans = std:: max(k2,ans);
            k2 = nex(k2);
            ans = std:: max(k2,ans);
        }while(k1 != k2);
        std:: cout << ans << '\n';
    }
    return 0;
}