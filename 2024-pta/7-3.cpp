#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int mp[11];
int a[11];
vector<int> v;
int vis[11];
int main(){
    string s;
    cin>>s;
    for(int i=0;i<11;i++){
        a[i]=s[i]-'0';
    }
    for(int i=0;i<11;i++){
        if(vis[a[i]]){
            continue;
        }else {
            v.push_back(a[i]);
            vis[a[i]]=1;
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<v.size();i++){
        mp[v[i]]=i;
    }
    cout<<"int[] arr = new int[]{";
    for(int i=0;i<v.size();i++){
        cout<<v[i];
        if(i!=v.size()-1){
            cout<<',';
        }
    }
    cout<<"};\n";
    cout<<"int[] index = new int[]{";
    for(int i=0;i<11;i++){
        cout<<mp[a[i]];
        if(i!=10){
            cout<<',';
        }
    }
    cout<<"};\n";
}