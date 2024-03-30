#include<cstdio>
using namespace std;
int main(){
    int a, b;
    int sum = 0;
    scanf("%d %d", &a, &b);
    int c, t;
    for (int i = 0; i < 3;i++){
        scanf("%d", &t);
        sum += t;
    }
    if(a>b&&sum<3){
        printf("The winner is a: %d + %d", a, 3 - sum);
    }else
        printf("The winner is b: %d + %d", b, sum);
}