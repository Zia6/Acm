#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int n;
    double m;
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        double t;
        cin >> t;
        if(t < m){
            printf("On Sale! %.1f\n", t);
        }
    }
}