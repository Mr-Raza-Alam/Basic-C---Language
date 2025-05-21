#include<iostream>
#include<string>
using namespace std;
class test;
class uniary{
    int a,b,c ;
  uniary(){// Default constructor
    a = 0;
    b = 0;
    c = 0;
  } 
 uniary(int i,int j , int k){// parameterised constructor
    this->a = i;
    this->a = j;
    this->a = k;
 } 
 friend void operator-(uniary &obj);
  void display();

};


void uniary :: display(){
    cout<<"a : "<<a<<endl;
    cout<<"b : "<<b<<endl;
    cout<<"c : "<<c<<endl;
}
// class Arithmatic : public uniary{// simple inheritance
//     int sum,diff,quo,mul;

//  public:
//   Arithmatic(){sum = 0; diff = 0; quo = 0; mul = 0}
  
  
// };
class test{
 public : 
 string s1;
  test operator+(test &obj){
    test temp;
     temp.s1 =  (this->s1+" "+obj.s1);
     return temp;
  }
  void display(){
    cout<<"Your string : "<<s1<<endl;
  }
};
int main(){
  test t1,t2,t3;
 string str1,str2;
 cout<<"Enter your 1st string : ";
 getline(cin,str1);
 t1.s1 = str1;
 cout<<"Enter your 2nd string : ";
 getline(cin,str2);
 t2.s1 = str2;

 t3 = t1 + t2;// operator overloading
 t3.display();
    return 0;
}
  // int a,b,c;
  // cout<<"Enter 1st one number : ";
  // cin>>a;
  // cout<<"Enter 2nd one number : ";
  // cin>>b;
  // cout<<"Enter 3rd one number : ";
  // cin>>c;


// class vector{
//     int opr1;
//     public:
//     vector(){ opr1 = 0;} 
//      vector(int op1){
//        this->opr1 = op1;
//      }
//    vector operator*(vector &obj);
//    void showResult();
 
 
//  };
 
//  vector vector :: operator*(vector &obj){
//      return (this->opr1 * obj.opr1);
//  }
 
//  void vector :: showResult(){
//      cout<<"Result : "<<opr1<<endl;
//  }