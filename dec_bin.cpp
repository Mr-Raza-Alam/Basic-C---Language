#include<iostream>
using namespace std;
int power(int c,int t){
    int j,p = 1;
    if(t==0) return 1;
    for(j = 1; j<=t; j++){
          p *= c;
    }
    return p;
}
int main (){
   int decnum,r,q,ans = 0,i = 0,binum;
   cout<<"Enter your desire binary  no. = \n";
   cin>>binum;
   /*cout<<"The decimal number "<< decnum <<" into binary digits = ";
    while(decnum>0){
        r = decnum%2;
        decnum /= 2;
        ans += r * power(10,i);
        i++;
    }
   cout<<ans<<endl;*/
   cout<<"The binary numbers "<< binum <<" into decimal number  = ";
    while(binum>0){
        r = binum%10;
        binum /= 10;
        ans += r * power(2,i);
        i++;
    }
     cout<<ans<<endl;
    return 0;
}