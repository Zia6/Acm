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
using ll = long long;
using ull = unsigned long long;

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
const int maxn = 5e5 + 5;
struct BIT{
    ll d[maxn];
    inline int lowbit(int x){
        return x & -x;
    }

    void add(int i,int x){
        while(i < maxn){
            d[i] += x;
            i += lowbit(i);
        }
    }

    ll gets(int x){
        ll sum = 0;
        while(x){
            sum += d[x];
            x -= lowbit(x);
        }
        return sum;
    }

    ll getSum(int x,int y){
        return gets(y) - gets(x - 1);
    }


};


BIT a;
int main() {
    int n,m,x;
    std::cin >> n  >> m;
    for(int i = 1;i <= n;i++){
        std:: cin >> x;
        a.add(i,x);
    }
    for(int i = 0;i < m;i++){
        int op,x,y;
        std::cin >> op >> x >> y;
        if(op == 1) a.add(x,y);
        else std::cout << a.getSum(x,y) << '\n';
    }
    return 0;
}