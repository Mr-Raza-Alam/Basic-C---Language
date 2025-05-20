#include<iostream>
using namespace std;
int power(int c,int t){
    int j,p = 1;
    if(t==0) return 1;
    for(j = 1; j<t; j++){
          p *= c;
    }
    return p;
}
int main (){
    short int x,t,i = 1,j,s = 0;
    cout<<"Enter your favourite no.= ";
    cin>> x;
   t = x;
    while(t>0){
        t /=10;
        i++;
    }
   cout<<"Total no. of digits is in no. "<<x<<" = "<<(i-1)<<endl;
      j = i-1;
   if(j==(i-1)){
        t = power(10,j);
   }
   
   for(i = 1; x>0; i++){
       s +=(x%10)*t;
       x /=10;
       t /=10;
   }
   cout<<"The reverse no. of the given no. = "<<s<<endl;
    return 0;
    //method -2
    /*while(x>0){
        s *=10;
        s += x%10;
        x /=10;
        i++;
    }
    cout<<"The reverse no. = "<<s<<endl;*/
}