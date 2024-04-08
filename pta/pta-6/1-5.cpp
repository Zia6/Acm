#include<cstdio>
#include<iostream>
using namespace std;
int a[24];
int main(){
    int n;
    for (int i = 0; i < 24;i++){
        cin >> a[i];
    }
    while(cin >> n && n >=0 && n < 24){
        if(a[n] > 50)
            cout << a[n] << " " << "Yes" << '\n';
        else
            cout << a[n] << " " << "No" << '\n';
    }
}