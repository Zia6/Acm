#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
void insert(int x){
    if(x < 10){
        q.push(x);
    }else {
        q.push(x/10);
        q.push(x % 10);
    }
}
int main(){
    int n;
    int a, b;
    cin >> a >> b >> n;
    int cnt = 0;
    insert(a);
    insert(b);
    while(!q.empty() && cnt < n){
        int now = q.front();
        q.pop();
        insert(now * q.front());
        cout << now;
        if(cnt < n - 1)
            cout << ' ';
        cnt++;
    }
}