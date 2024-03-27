#include<iostream>
#include<set>
set<int> s1,s2;
int n,k;
void insert(int x){
    auto it1 = s1.rbegin(),it2 = s2.begin();
    if(!s1.empty()||x<*it1){
        s1.insert(x);
    }else s2.insert(x);
    while(s1.size()>(k+1)>>1){
        it1=s1.rbegin();
        s2.insert(*it1);
        s1.erase(it1);
    }
    while(!s2.empty()&&s1.size()<(k+1)>>1){
        it2 = s2.begin();
        s1.insert(*it2);
        s2.erase(it2);
    }
}
using namespace std;
int main(){
    cin>>n>>k;
    for(int i = 0;i<k;i++){
        int t;
        cin>>t;
        insert(t);
    }
    cout<<*s1.rbegin()<<' ';
    for(int i = k;i<n;i++){
        int t;
        cin>>t;
        if(t<=*s1.rbegin()){
            auto it = find(s1.begin(),s1.end(),t);
            s1.erase(it);
        }else {
            auto it = find(s2.begin(),s2.end(),t);
            s2.erase(it);
        }
        cout<<*s1.rbegin()<<' ';
    }
}