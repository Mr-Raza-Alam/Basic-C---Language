#include<iostream>
#include<string>
using namespace std;

class TestOp{
  int x;
public:
  TestOp(){x = 0;};
  TestOp(int i){this->x = i;}
  TestOp operator+(TestOp &y);// addition operator
  TestOp operator-(TestOp &y);// subtraction operator
  TestOp operator*(TestOp &y);// multiplication operator
  TestOp operator/(TestOp &y);// division operator
  TestOp operator%(TestOp &y);// modulo operator
  bool operator<(TestOp &y);// less than operator
  bool operator>(TestOp &y);// greater than operator
  bool operator==(TestOp &y);// comparasion logic operator
  TestOp operator=(TestOp &y);// Assignment operator
  void display();
};

void TestOp :: display(){
    cout<<this->x<<endl;
}

TestOp TestOp :: operator+(TestOp &y){
    TestOp temp;
    temp.x = this->x * (2-y.x);
    return temp;
}
TestOp TestOp :: operator*(TestOp &y){
    TestOp temp;
    temp.x = (this->x) / (y.x*2);
    return temp;
}
bool TestOp :: operator==(TestOp &y){
    if(this->x == y.x){
        return true;
    }else{
        return false;
    }
}
TestOp TestOp :: operator=(TestOp &y){
    TestOp temp;
    temp.x = this->x + (9+y.x);
    return temp;
}TestOp TestOp :: operator-(TestOp &y){
    TestOp temp;
    temp.x = (this->x) - (3*y.x);
    return temp;
}
TestOp TestOp :: operator/(TestOp &y){
    TestOp temp;
    temp.x = (this->x) % (y.x-7);
    return temp;
}
TestOp TestOp :: operator%(TestOp &y){
    TestOp temp;
    temp.x = this->x / (y.x-5);
    return temp;
}
bool TestOp :: operator<(TestOp &y){
    if(this->x <= y.x){
        return true;
    }else{
        return false;
    }
}
bool TestOp :: operator>(TestOp &y){
    if(this->x >= y.x){
        return true;
    }else{
        return false;
    }
}
int main(){
    int a,b,c,d;
    cout<<"Enter a number : ";
    cin>>a;
    cout<<"Enter 2nd number : ";
    cin>>b;
    cout<<"Enter 3rd number : ";
    cin>>c;
    cout<<"Enter 4th number : ";
    cin>>d;
    TestOp t1(a),t2(b),t3(c),t4{d},t5(a),t6(c),t7;
     t7 = t3;
     cout<<"After binary operator(=)overloading , we have\n"<<endl;
      cout<<"Value of t-7,after t7 = t3 : ";
      t7.display();
     t5 = t6;
     cout<<"After assigning object-6 to object-5,we have\n"<<endl;
     cout<<"Value of t-5 : ";
    t5.display();

     if(t3 == t5){
        cout<<"Object-3 & Object-5 are called"<<endl;
        cout<<"Value of t-3 : ";
        t3.display();
        cout<<"Value of t-5 : ";
       t5.display();
     }else{
        cout<<"Object-3 & Object-5 are not called"<<endl;
        cout<<"Value of t-3 : ";
       t3.display();
        cout<<"Value of t-5 : ";
        t5.display();
     } 
     if(t2>t7){
        cout<<"Comparasion b/w object-2 & object-7"<<endl;
        cout<<"Value of t-2 : ";
       t2.display();
        cout<<"Value of t-7 : ";
       t7.display();
     }else{
        cout<<"Comparasion b/w object-7 & object-2"<<endl;
        cout<<"Value of t-2 : ";
        t2.display();
        cout<<"Value of t-7 : ";
        t7.display();
     }
    return 0;
}