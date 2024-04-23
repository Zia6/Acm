#include<cstdio>
#include<set>
using namespace std;
set<int> s;
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        int t;
        scanf("%d", &t);
        s.insert(t);
    }
    printf("%d", s.size());
}