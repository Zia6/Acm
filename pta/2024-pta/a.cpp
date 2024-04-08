#include<iostream>
using namespace std;
const int N=1000;
int stoint(string s){
    if(s.size()>4)
        return -1;
    int ans=0;
    if(s.size()==1&&s[0]=='0') return 0;
    for(int i=0;i<=s.size()-1;i++){
        ans*=10;
        if(s[i]-'0'>9||s[i]-'0'<0||(ans==0&&s[i]-'0'==0)){
            return -1;
        }
        ans+=(s[i]-'0');
    }
    return ans;
}
int main(){
    int n;
    string s1,s2;
    cin>>s1>>s2;
    int ans=0;
    if(stoint(s1)==-1) ans+=0;
    else 
    ans+=stoint(s1);
    if(stoint(s2)==-1) ans+=0;
    else 
    ans+=stoint(s2);
    if(stoint(s1)==-1) cout<<"? ";
    else cout<<s1<<' ';
    cout<<"+ ";
    if(stoint(s2)==-1) cout<<"? ";
    else cout<<s2<<' ';
    cout<<"= ";
    if(stoint(s1)==-1||stoint(s2)==-1){
        cout<<"?\n";
    }else 
    cout<<ans<<'\n';
}