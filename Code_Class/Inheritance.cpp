#include<iostream>
#include<string>
using namespace std;

class parent{
 private:
  int a,b;
 public:
  // parameterise constructor
  parent(int x,int y){
    this->a = x;
    this->b = y;
  }

 // member function
 void getParent(){
    cout<<"Hello dear childrens , here i am your parent "<<endl;
    cout<<"Child-1 : "<<a<<endl;
    cout<<"Child-2 : "<<b<<endl;
 }
 void getSum();

};
void parent :: getSum(){
    cout<< a<<" + "<<b<<" = "<<(a+b)<<endl;
}


class child: public parent{ // simple inheritance in protected mode -> inaccessible by its object
   private:
    int p,t;
   public:
  // parameterise constructor
  child(int x,int y){
    this->p = y;
    this->t = x;
  }

   // member function
   void getDiff();
};
void child :: getDiff(){
    cout<< p<<" - "<<t<<" = "<<(p-t)<<endl;
}
int main(){
  int x,y;
  cout<<"Enter 1st num: ";
  cin>>x;
  cout<<"Enter 2nd num: ";
  cin>>y;
  parent p(y,x);

  child c(x,y);
  p.getParent();
  c.getSum();
  c.getDiff();

 return 0;
}