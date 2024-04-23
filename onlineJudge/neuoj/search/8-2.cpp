#include<iostream>
using namespace std;
const int maxn = 2e5 + 5;
long long s[maxn];
int n, k;
int low_bit(int x){
    return x & -x;
}
long long gets(int x){
    long long ans = 0;
    while(x){
        ans += s[x];
        x -= low_bit(x);
    }
    return ans;
}
long long getsum(int l,int r){
    return gets(r) - gets(l - 1);
}
void update(int index,int x){
    while(index <= n){
        s[index] += x;
        index += low_bit(index);
    }
}
int main(){
    cin >> n;
    k = 1;
    for (int i = 1; i <= n;i++){
        update(i, 1);
    }
    int x = 1;
    for (int i = 1; i <= n;i++){
        x = (k + x) % (n - i + 1);
        if(x == 0)
            x = n - i + 1;
        int l = 1, r = n;
        while(l < r){
            int mid = (l + r) >> 1;
            if(gets(mid) >= x){
                r = mid;
            }else
                l = mid + 1;
        }
        update(l, -1);
        cout << l << ' ';
    }
}