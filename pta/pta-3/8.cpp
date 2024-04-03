#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1e4 + 5;
struct node{
    string s;
    double value;
    bool operator < (const node&n){
        return value < n.value;
    }
}a[N];
int main(){
    int n;
    int sum = 0;
    double ave;
    scanf("%d",&n);
    for (int i = 0; i < n;i++){
        cin >> a[i].s >> a[i].value;
        sum += a[i].value;
    }
    ave = 1.0 * sum / n / 2;
    for (int i = 0; i < n;i++){
        a[i].value = fabs(1.0 * a[i].value - ave);
    }
    sort(a, a + n);
    printf("%.0f ", ave);
    cout << a[0].s;
}