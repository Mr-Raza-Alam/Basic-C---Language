// prime factor of any number
 
#include<iostream>
#include<string>
using namespace std;

 bool isPrime(int k){
   for(int i = 2;i<=k/2; i++){
    if(k%i==0){
        return false;
    }
   }
   return true;
 }

int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Prime factor of "<<n<<" are : \n";
  for(int i = 2; i<n; i++){
     if(isPrime(i) == true){
       if(n%i == 0){
        cout<<i<<" ";
       }
     }
  }
  return 0;
}