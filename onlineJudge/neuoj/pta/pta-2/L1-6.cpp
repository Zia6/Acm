#include<iostream>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin>>t;
    ll s,m=1,n=1;
    while(m%t!=0&&n<190){
        n++;
        m=m*10+1;
    }
    cout<<m/t<<' '<<n<<'\n';
}