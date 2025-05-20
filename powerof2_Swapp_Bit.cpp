#include<iostream>
using namespace std;

void swapp(){
  int a,b;
  cout<<"Enter your 1st number : ";
  cin>>a;
  cout<<"Enter your 2nd number : ";
  cin>>b;
  cout<<"Before swapping"<<endl;
  cout<<"a : "<<a<<"\nb : "<<b<<endl;
 // use bitwise xor operator to swapp the given 2 numbers
  a = a^b;
  b = a^b;
  a = a^b;
  cout<<"After swapping"<<endl;
  cout<<"a : "<<a<<"\nb : "<<b<<endl;
}


int main (){//this is valid accept some no. like 36,52,100,etc; to figure out whether the given no. is the form of power of 2 or not;
    short int n,i,k;
    swapp();
    cout<<"Enter a no. = ";
    cin>> n;
    for(i = 1; n>0 ; i++){
        if(n%2==0 || n==1){
              n = n>>i;
            k = 0;
        }
        else {
            k = 1;
          cout<<"The given no. is not form of power of 2"<<endl;
            break;
        }
    }
   if(k==0) cout<<"The given no. is the form of power of 2"<<endl;
    return 0;
}