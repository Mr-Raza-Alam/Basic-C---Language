#include<iostream>
using namespace std;
int main (){
    int a,b,i;
    cout<<"Enter your 1st decimal no. = ";
    cin>>a;
    cout<<"Enter your 2nd decimal no. = ";
    cin>>b;
    cout<<"Enter the no. of shifting places = ";
    cin>>i;
    cout<<a<<" and & "<<b<<" = "<<(a & b)<<endl;
    cout<<a<<" or | "<<b<<" = "<<(a | b)<<endl;
    cout<<a<<" xor ^ "<<b<<" = "<<(a ^ b)<<endl;
    cout<<a<<" << leftshift "<<i<<" = "<<(a << i)<<endl;
    cout<<a<<" << rightshift "<<i<<" = "<<(a >> i)<<endl;
    return 0 ;
}