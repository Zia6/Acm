#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=11;
int c[N][N];
int fac[N];
void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<N;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++){
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    fac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i;
    }
}
vector<int> v;
void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    int ans=0;
    for(int i=0;i<fac[n];i++){
        ans=0;
        for(int i=0;i<=n;i++){
            ans+=c[n-1][i]*v[i];
        }
        if(ans==k){
            for(int i=0;i<n;i++){
                cout<<v[i]<<" ";
            }
            cout<<'\n';
            return;
        }
        next_permutation(v.begin(),v.end());
    }
}
int main(){
    init();
    solve();
}