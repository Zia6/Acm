#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<double> v;
void solve(){
    int n,k,m;
    cin>>n>>k>>m;
    for(int i=0;i<n;i++){
        double ans=0;
        double maxm=-1,minm=1000;
        for(int j=0;j<k;j++){
            double x;
            cin>>x;
            maxm=max(maxm,x);
            minm=min(minm,x);
            ans+=x;
        }
        ans-=(maxm+minm);
        ans/=(k-2);
        v.push_back(ans);
    }
    sort(v.begin(),v.end(),greater<double>());
    for(int i=m-1;i>=0;i--){
        printf("%.3f",v[i]);
        if(i!=0){
            cout<<' ';
        }
    }
}
int main(){
    solve();
}