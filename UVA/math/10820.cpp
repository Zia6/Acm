#include<iostream>
using namespace std;
const int maxn = 5e4 + 5;
int pi[maxn], prime[maxn], pre[maxn];
int cnt = 0;
void init(){
    pi[1] = 1;
    for (int i = 2; i < maxn;i++){
        if(!pi[i]){
            pi[i] = i - 1;
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * prime[j] < maxn;j++){
            pi[i * prime[j]] = pi[i] * pi[prime[j]];
            if(i % prime[j] == 0){
                pi[i * prime[j]] = prime[j] * pi[i];
                break;
            }
        }
    }
    for (int i = 1; i < maxn;i++){
        pre[i] = pi[i] + pre[i - 1];
    }
}
int main(){
    init();
    int n;
    while(cin >> n && n){
        cout << 2 * pre[n] - 1 << '\n';
    }
}