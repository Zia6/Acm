#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    double a, b;
    scanf("%lf %lf", &a, &b);
   
    b = b * b;
    printf("%.1f\n", a / b);
    if(a/b > 25){
        printf("PANG");
    }else {
        printf("Hai Xing");
    }
}