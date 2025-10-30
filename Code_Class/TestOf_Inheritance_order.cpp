#include<iostream>
#include<string>
using namespace std;
class Base1;
class base{
  // privated section
  int a ,b,c;
  void answer();
  // protected section
  protected:
   void pro_member(){
    cout<<"This is a protected mode member function of class"<<endl;
   }
  // public section
  public:
   base(){a = 0; b = 0; c = 0;}
   base(int i,int j,int k){this->a = i; this->b = j; this->c = k;}
   void show();

  void get_Base();
};

void base :: show(){
    cout<<"Value of private data members are given below : "<<endl;
    cout<<"a : "<<this->a<<"\nb : "<<this->b<<"\nc : "<<this->c<<endl;
}

void base :: get_Base(){
    cout<<"Hey, this is a base class. what do you like to do"<<endl;
}

class Base1{
// privated section
 int x,y;
 void funBase(){
    cout<<"This is base1 member function"<<endl;
 }
// protected section
 protected :
 void sum(){
      cout<<"Sum of Pro-base_1 : "<<(this->x + this->y)<<endl;
 }
 // public section
 public:
  Base1(){x = 0; y =0;}
  Base1(int p,int q){x = p; y = q;}

  void display_Base1(){
    cout<<"X : "<<x<<"\nY : "<<y<<endl;
  }
};

class derive1 : public Base1,public base{
 float p,q;
 public:
  derive1(){p = 0.0; q = 0.0;}
  derive1(float f,float g,int s,int p,int v,int u,int w):base(s,p,v),Base1(u,w){this->p = f; this->q = g;}

 void der1_show(){
    cout<<"P : "<<p<<"\nQ : "<<q<<endl;
 }
};
int main(){
   int a,b,c,d,e;
   float x,y;
   cout<<"Enter a , b, c , d , e : ";
   cin>>a>>b>>c>>d>>e;
   cout<<"Enter x, y :";
   cin>>x>>y;
   derive1 d1(x,y,a,b,c,d,e),d2,d3;
   d2.der1_show();// derived class called.
    d1.get_Base();// 2nd base class  called 
   d1.display_Base1();// 2nd base class called.
   d1.show();// 1st base class called.
    return 0;
}

