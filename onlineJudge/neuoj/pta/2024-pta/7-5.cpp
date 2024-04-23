#include<iostream>
using namespace std;
int main(){
    double H;
    cin>>H;
    //保留一位小数
    cout.setf(ios::fixed);
    cout.precision(1);
    cout<<(H-100)*0.9*2<<'\n';
}