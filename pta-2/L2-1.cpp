#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int N=105;
struct node{
    string s;
    int cnt;
    int sum;
    bool operator < (const node n)const {
        return cnt==n.cnt?sum>n.sum:cnt<n.cnt;
    }
};
node a[N];
map<int,int> vis;
int main(){
    int n,k,t;
    cin>>n;
    for(int i=0;i<n;i++){
        vis.clear();
        cin>>a[i].s>>k;
        for(int j=0;j<k;j++){
            cin>>t;
            if(!vis.count(t)){
                vis.insert({t,0});
                a[i].cnt++;
            }
            vis[t]++;
        }
        a[i].sum=k;
        // cout<<a[i].cnt<<'\n';
    }
    sort(a,a+n);
    if(n<3){
        for(int i=n-1;i>=0;i--){
            cout<<a[i].s<<' ';
        }
        for(int i=0;i<3-n;i++){
            cout<<"-";
            if(i!=2-n) cout<<' ';
        }
    }else {
        for(int i=n-1;i>=n-3;i--){
            cout<<a[i].s;
            if(i!=n-3) cout<<' ';
        }
    }
}