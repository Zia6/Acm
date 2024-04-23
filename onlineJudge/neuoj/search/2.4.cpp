#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> s;
int main(){
    int n, m, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n;i++){
        scanf("%d", &t);
        s.push_back(t);
    }
    sort(s.begin(),s.end());
    for (int i = 0; i < m;i++){
        scanf("%d", &t);
        auto it = upper_bound(s.begin(), s.end(), t);
        if(it == s.begin()){
            printf("-1\n");
        }
        else {
            printf("%d\n", *(--it));
            s.erase(it);
        }
    }
}