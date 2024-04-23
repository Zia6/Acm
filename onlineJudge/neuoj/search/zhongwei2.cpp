#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
multiset<int> s1,s2;
const int maxn = 2e5 + 5;
int a[maxn];
int n,k;
void insert(int x){
    if(!s1.empty()&&x<*s1.rbegin()){
        s1.insert(x);
    }else s2.insert(x);
    while(s1.size()>(k+1)>>1){
        s2.insert(*s1.rbegin());
        s1.erase(--s1.end());
    }
    while(!s2.empty()&&s1.size()<((k+1)>>1)){
        s1.insert(*s2.begin());
        s2.erase(s2.begin());
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i = 0;i<k;i++){
        cin >> a[i];
        insert(a[i]);
    }
    cout<<*s1.rbegin()<<' ';
    for(int i = k;i<n;i++){
        cin >> a[i];
        if(a[i-k]<=*s1.rbegin()){
            s1.erase(find(s1.begin(),s1.end(),a[i-k]));
        }else {
            s2.erase(find(s2.begin(),s2.end(),a[i-k]));
        }
        

        insert(a[i]);
        // for(auto it : s1){
        //     cout << it << ' ';
        // }
        // for(auto it : s2){
        //     cout << it << ' ';
        // }
        //         cout << '\n';
        cout<<*s1.rbegin()<<' ';
    }
}