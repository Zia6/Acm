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
const int maxn = 1e6 + 5;
long long a[maxn],c[maxn],s[maxn];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    while(std:: cin >> n){
        std:: vector<long long> v;
        long long ave;
        for(int i = 1;i <= n;i++) {
            std:: cin >> a[i];
            s[i] = s[i - 1] + a[i];
        }
        ave = s[n] / n;
        for(int i = 1;i <= n;i++){
            c[i] = s[i] - i * ave;
            v.push_back(c[i]); 
        }
        std:: sort(v.begin(),v.end());
        unsigned long long ans = 0;
        for(int i = 0;i < n;i++){
            ans += abs(v[n / 2] - v[i]);
        }
        std:: cout << ans << '\n';
        v.clear();
    }
    return 0;
}