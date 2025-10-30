#include<iostream>
#include<string>
using namespace std;
class uniary{
    int a,b,c ;
  uniary(){
    a = 0;
    b = 0;
    c = 0;
  } 
 uniary(int i,int j , int k){
    this->a = i;
    this->a = j;
    this->a = k;
 } 
 friend void operator-(uniary &obj);
  void display();

};

friend void uninary :: operator-(uniary &obj){
  obj.a = -obj.a
  obj.b = -2*obj.b;// 
  obj.c = -4+obj.c;//
}
 
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

int main(){
  int a,b ;
  cout<<"Enter 1st one number : ";
  cin>>a;
  cout<<"Enter 2nd one number : ";
  cin>>b;
  cout<<"Enter 3rd one number : ";
  cin>>c;
  uniary u1(a,b,c),u2(c,a,b),u3;
     -(u3);
    u3.display();
  //   vector v(a),v2(b),v3;
//   v3 = v * v2;
//   v3.showResult();

    return 0;
}

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