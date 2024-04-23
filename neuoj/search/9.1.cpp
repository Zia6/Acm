#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int main(){
    int n;
    cin >> n;
    long long now = 0;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n;i++){
        if(a[i] > now + 1){
            cout << now + 1 << '\n';
            return 0;
        }else {
            now = now + a[i];
        }
    }
    cout << now + 1 << '\n';
}