#include<iostream>
#include<cmath>
using namespace std;
char a[7];
int main(){
    int l, n;

    cin>>l>>n;
        int m = pow(26, l);
    m -= n;
    // cout << m << '\n';
    for (int i = 0; i < l;i++){
        a[i] = 'a'+ m / pow(26, l - i - 1);
        m %= (int)pow(26, l - i - 1);
        // cout << m << '\n';
    }
    for (int i = 0; i < l;i++){
        cout << a[i];
    }
}