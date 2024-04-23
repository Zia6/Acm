#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    double s = 0.1 * b * a;
    printf("%.2f", s);
}