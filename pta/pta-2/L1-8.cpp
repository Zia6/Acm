#include<iostream>
using namespace std;
const int N=105;
int a[N][N],b[N][N],ans[N][N];
int main(){
    int r1,c1,r2,c2;
    cin>>r1>>c1;
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin>>a[i][j];
        }
    }
    cin>>r2>>c2;
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin>>b[i][j];
        }
    }
    if(c1!=r2){
        cout<<"Error: "<<c1<<" != "<<r2<<'\n';
        return 0;
    }else {
        cout<<r1<<' '<<c2<<'\n';
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                for(int k=0;k<r2;k++){
                    ans[i][j]+=a[i][k]*b[k][j];
                }
                cout<<ans[i][j];
                if(j!=c2-1)
                cout<<' ';
            }
            if(i!=r1) cout<<'\n';
        }
    }
}