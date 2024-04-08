#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 1e6 + 5;
int a[maxn], cnt[maxn];
int main(){
    int n;
    cin >> n;
    int mi = 1e9 + 5,ma = -1;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        cnt[a[i]]++;
        mi = min(mi, a[i]);
        ma = max(ma,a[i]);
    }
    cout << mi << ' ' << cnt[mi] << '\n';
    cout << ma << ' ' << cnt[ma];
}