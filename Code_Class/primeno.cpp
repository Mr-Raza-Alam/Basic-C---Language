#include<iostream>
#include<stdbool.h>
using namespace std;
/*void prime(int a){
   // bool flag = false;
  for(int i = 2; i*i<=a;i++){
    if(a%i==0) {
       cout<<a<<" is a non-prime number"<<endl;
    }
  }
    cout<<a<<" is a prime no. "<<endl;
  //if(flag== false) cout<< a <<" is a prime no."<<endl;
  //else cout<< a <<" is a composite no."<<endl;
}*/
void Nprime(int a){
  int count=0;
  for(int i = 2; i<=a;i++){
       bool flag = false;
    for(int j = 2; j<=i/2; j++){
      if(i%j==0){
         flag = true;
      }
    }
  if(flag== false){
     cout<< i <<endl;
      count++;
    }
  }
  cout<<"The total no. of prime numbers given above b/w 1 to "<<a<<" = "<<count<<endl;
}

int main (){
   int n;
   cout<<"Enter the range b/w 1 to n = ";
   cin>>n;
   cout<<"The prime no.s b/w 1 to "<< n <<" are :-"<<endl;
    Nprime(n);
    return 0;
}