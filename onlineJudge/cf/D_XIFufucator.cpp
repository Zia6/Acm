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
#define mp std::make_pair
#define pr std::pair
#define int long long
using ll = long long;

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
const int c1 = 211;
const int c2 = 281;
const int p1 = 1e9 + 7;
const int p2 = 998244353;
const int maxn = 3e5 + 5;
int poww[2][maxn];
std:: string v[maxn],s[maxn];
std::vector<int> pos[maxn];
std:: map<pr<int,int>,int> count;
std:: map<pr<int,int>,pr<int,int>> solution;
void init(){
    for(int i = 1;i < maxn;i++ ){
        poww[0][i] = 1ll * poww[0][i - 1] * c1 % p1;
        poww[1][i] = 1ll * poww[1][i - 1] * c2 % p2; 
    }
}

pr<int,int> get_hash(std::string& s){
    int l = s.size();
    pr<int,int> ans;
    for(int i = 0;i < l;i++){
        ans.first = (ans.first * c1 + s[i]) % p1;
        ans.second = (ans.second * c2 + s[i]) % p2;
    }
    return ans;
}

pr<int,int> modify_hash(std::string& s,pr<int,int> val,int index){
    val.first -= s[index] * poww[0][index] % p1;
    val.first += (s[index] ^ 1)* poww[0][index] % p1;
    val.first += p1;
    val.first %= p1;

    val.second -= s[index] * poww[1][index] % p2;
    val.second += (s[index] ^ 1)* poww[1][index] % p2;
    val.second += p2;
    val.second %= p2;
    return val;
}
void solve(){
    int n,m;
    count.clear();
    solution.clear();
    read(n),read(m);
    for(int i = 0;i < m;i++) pos[i].clear();
    for(int i = 0;i < n;i++){
        std:: cin >> s[i];
        for(int j = 0;j < m;j++){
            if(s[i][j] == '1')
            pos[j].push_back(i);
        }
    }
    for(int j = 0;j < m;j++){
        std::string t;
        for(int i = 0;i < n;i++){
            t.push_back('0');
        }
        for(auto& p:pos[j]){
            t[p] = '1'; 
        }
        pr<int,int> now = get_hash(t);
        for(int i = 0;i < n;i++){
            pr<int,int> tem = modify_hash(t,now,i);
            if(!solution.count(tem)) solution[tem] = mp(i,j);
            count[tem]++;
        }
    }
    pr<pr<int,int>,int> ans; 
    for(auto& tem:count){
        if(tem.second > ans.second) ans = tem;
    }
    int ans1 = ans.second;
    pr<int,int>sol = solution[ans.first];
    std::string ss,ans2;
    for(int i = 0;i < n;i++){
        ss.push_back('0');
    } 
    for(auto& x: pos[sol.second]){
        ss[x] = '1';
    }
    ss[sol.first] ^= 1;
    ans2 = ss;
    std:: cout << ans1 << '\n' << ans2 << '\n';
}
signed main() {
    int T;
    read(T);
    init();
    while(T--){
        solve();
    }
    return 0;
}