#include<cstdio>
using namespace std;
int main(){
    double x, ans, m;
    int t;
    scanf("%lf %d %lf", &x, &t, &m);
    if(t){
        ans = x * 1.26;
    }else
        ans = x * 2.455;
    printf("%.2lf ", ans);
    if(ans > m){
        printf("T_T");
    }else
        printf("^_^");
}