#include<iostream>
#include<string>
using namespace std;

class base{
 public:
  virtual void display(){
    cout<<"Base class is display"<<endl;
  }
 virtual void show(){// now we can able to use single pointer to access all base member's fun alongwith other classes 's member fun.
    cout<<"Base class is shown"<<endl;
  }
};

class derive : public base{
  public:
  void display(){
    cout<<"Derived class is display"<<endl;
  }
  void show(){
    cout<<"Derived class is shown"<<endl;
  } 
};

int main(){
  base b;
  derive d;
  base *bptr;
  cout<<"-----base class------"<<endl;
  // call base member's fun. using bptr but before we have to assign address of base class to bptr
  bptr = &b;
  bptr->display();
  bptr->show();
  // now it time for derive class 
  cout<<"-----Derived class------"<<endl;
  bptr = &d;
  bptr->display();
  bptr->show();
    return 0;
}
