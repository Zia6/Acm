#include<iostream>
using namespace std;
const int maxn = 5e4 + 5;
int pi[maxn], prime[maxn]; // 欧拉函数 质数
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
}