#include<iostream>
 using namespace std;

 int divide(int num, int den){
    if(den == 0){
      throw (1);
    }else if(den < 0){
        throw ("error");
    }
   return (num/den);
 }

 int main(){
   int a,b,z;
  cout<<"Enter a numerator : ";
  cin>>a;
  cout<<"Enter a denomenator : ";
  cin>>b;
  try{
    z = divide(a,b);
    cout<<"Value of z : "<<z<<endl;
  }catch(int n){
     cout<<"Divison by Zero\n"<<endl;
  }catch(const char*msg){
    cout<<"Unexpected Error!!"<<endl;
  }
    return 0;
 }
 