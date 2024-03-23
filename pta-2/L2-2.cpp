#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+5;
struct node{
    int nex;
    int data;
}a[N];
vector<int> v;
string f(int x){
    if(x>=10000||x==-1) return "";
    else if(x>=1000) return "0";
    else if(x>=100) return "00";
    else if(x>=10) return "000";
    else if(x>=1) return "0000";
    else return "0000";
}
int main(){
    int n;
    int en,st;
    cin>>st>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m>>a[m].data>>a[m].nex;
        if(a[m].nex==-1) en=m;
    }
    int m=st;
    while(m!=-1){
        v.push_back(m);
        m=a[m].nex;
    }
    int l=0,r=v.size()-1;
    while(l<r){
        
        cout<<f(v[r])<<v[r]<<' '<<a[v[r]].data<<' '<<f(v[l])<<v[l]<<'\n';
        if(r>l+1)
        cout<<f(v[l])<<v[l]<<' '<<a[v[l]].data<<' '<<f(v[r-1])<<v[r-1]<<'\n';
        else cout<<f(v[l])<<v[l]<<' '<<a[v[l]].data<<' '<<"-1"<<'\n';
        l++;
        r--;
    }
    if(l==r) cout<<f(v[r])<<v[r]<<' '<<a[v[r]].data<<' '<<f(a[v[r]].nex)<<a[v[r]].nex<<'\n';
}