#include<iostream>
using namespace std;

int sqRt(int n){
  int t = 0,lb = 0,ub = n;
  while(lb <= ub){
    t = (lb + ub)/2;
    int p = t * t;
   if(p == n){
    return t;
   } else if(p > n){
    ub = t;
   }else{
    lb = t;
   }
  }
  return -1;// that means no square root exit for -ve numbers
}
int main(){
  int n;
  cout<<"Enter your desire number = ";
  cin>>n;
  cout<<"The square root of "<<n<<" = "<<sqRt(n)<<endl;    
 return 0;
}