#include<cstdio>
using namespace std;
int a[105][105];
int main(){
    int n;
    char c;
    scanf("%c", &c);
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            a[i][j] = getchar();
        }
        getchar();
    }
    bool is = false;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(a[i][j] != a[n-1-i][n-1-j]){
                is = true;
                break;
            }
        }
    }
    if(!is){
        printf("bu yong dao le\n");
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(a[n-1-i][n-1-j]!=' '){
                printf("%c", c);
            }else
                printf(" ");
        }
        if(i<n-1)
            printf("\n");
    }
}