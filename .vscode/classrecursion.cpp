#include<iostream>
using namespace std;

int fib(int a){
    if(a == 0 || a==1){
        return a;
    }
    return fib(a-1) + fib(a-2);
}

int  main(){
    int n;
    cout<<"Enter a no. = ";
    cin>>n;
    int res = fib(n);
    cout<<res;
    return 0;
}