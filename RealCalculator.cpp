#include<iostream>
using namespace std;
 double ans = 0.0;
  double sqRT(double num){
    for(int i = 2; i<=num; i+=2){
       if(i*i == num){
        return i;
       }
    }
     return -1;
  }
int main(){
    cout<<"Welcome in Real Calculator World"<<endl;
    cout<<"7  8  9  Reset\n4  5  6   +\n1  2  3   -\n0  *  /   ="<<endl;
    double opr,newOpr;// operand
    char opt;// operator
    cout<<"Start your calculation\n";
    cout<<"Enter a number = "<<endl;
    cin>>opr;
    ans = opr;
    while(1){
        cin>>opt;
      if(opt == '+'){
         cin>>newOpr;
         ans += newOpr;
      } else if(opt == '-'){
         cin>>newOpr;
         ans -=newOpr;
      } else if(opt == '*'){
        cin>>newOpr;
        ans *=newOpr;
      }else if(opt == '/'){
        cin>>newOpr;

        ans /=newOpr;
      } else if(opt == '='){
         cout<<"\n"<<ans;
      } else if(opt == 'R'){
        cout<<"Restart your calculation"<<endl;
        ans = 0;
      } else if(opt == '?'){
        cout<<"I hope you had enjoy the calculation! Visit again"<<endl;  
        break;
      } else{
        cout<<"Come again"<<endl;
        break;
      }
    }
    double res = sqRT(opr);
    cout<<"The square root of "<<opr<<" = "<<res<<endl;
    return 0; 
}
    //  double lb,ub,temp;
    //  lb = 0;// lower-bound 
    //  ub = num;// upper-bound
    //  temp = 0;// temp -container
    //  while(lb < ub){
    //    temp = (lb+ub)/2;
    //    if(temp * temp == num){
    //     return temp;
    //    } else if(temp * temp > num){
    //      ub = temp;
    //    } else{
    //     lb = temp;
    //    }
    //  }