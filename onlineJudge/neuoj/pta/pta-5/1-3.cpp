#include<cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    double ans = 0;
    for (int i = 0; i < n;i++){
        double d;
        scanf("%lf", &d);
        ans += 1.0 / d;
        // printf("%.2f %.2f ", d, ans);
    }
    ans /= n;
    ans = 1 / ans;
    printf("%.2lf", ans);
}