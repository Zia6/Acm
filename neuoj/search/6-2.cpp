#include<iostream>
using namespace std;
int main(){
    int n, _max = -1, t;
    long long sum = 0, ans;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> t;
        _max = max(_max, t);
        sum += t;
    }
    cout << max(1ll * _max * 2, sum);
}