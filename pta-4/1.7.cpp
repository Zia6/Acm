#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0){
            if(b < 129){
                printf("duo chi yu! ");
            }else if(b > 129)
                printf("ni li hai! ");
            else
                printf("wan mei! ");
            if(c < 25){
                printf("duo chi rou!\n");
            }else if(c > 25){
                printf("shao chi rou!\n");
            }else
                printf("wan mei!\n");
        }else if(a == 1){
            if(b < 130){
                printf("duo chi yu! ");
            }else if(b > 130)
                printf("ni li hai! ");
            else
                printf("wan mei! ");
            if(c < 27){
                printf("duo chi rou!\n");
            }else if(c > 27){
                printf("shao chi rou!\n");
            }else
                printf("wan mei!\n");
        }
    }
}