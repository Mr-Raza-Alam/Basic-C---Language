#include <iostream>
using namespace std;
void  sumofterm(int a,int i,int s){
      while(i<=a){
        if(i==1)cout<< i ;
        else cout<< " + "<< i;
        s += i;
        i++;
      }
   cout<< "\nThe sum of the given series = " <<s<<endl;
      
}
int main (){
    int n;
   cout<<"Enter the total no. of terms = ";
   cin>> n;
   cout<<"sum = "<< n*(n+1)/2<<endl;
   sumofterm(n,1,0);
}