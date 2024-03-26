#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
priority_queue<int,vector<int>,greater<int>> q1;
priority_queue<int, vector<int>, less<int>> q2;
int n, k, a[maxn];
void insert(int x){
    if(q2.empty()||x<q2.top()){
        q2.push(x);
    }else
        q1.push(x);
    while(q2.size()>((k+1)>>1)){
        int t = q2.top();
        q2.pop();
        q1.push(t);
    }
    while(!q1.empty()&&q2.size()<((k+1)>>1)){
        int t = q1.top();
        q1.pop();
        q2.push(t);
    }
}
int main(){
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k;i++){
        scanf("%d", a + i);
        insert(a[i]);
    }
    printf("%d ", q2.top());
    for (int i = k; i < n;i++){
        scanf("%d", a + i);
        k += 2;
        if(a[i-k]<q2.top()){
            insert(inf);
        }else {
            insert(0);
        }
        insert(a[i]);
        printf("%d ", q2.top());
    }
}