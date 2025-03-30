#include<iostream>
#include<vector>
using namespace std;

class Stack{
  private :
   vector<int> vec;
   public :
     void push(int data);
  public :
    void pop();
  public :
   void peek();
  public :
   bool isEmpty();
  public :
   void  display_Data();
  public :
    int stack_Capacity();
};

void Stack :: push(int data){
    vec.push_back(data);
}
void Stack :: pop(){
    if(vec.size()==0){
     cout<<"Stack UnderFlow"<<endl;
     return;// -1 means stack is empty
    }
    vec.pop_back();// void type
}
void Stack :: peek(){
   cout<<"At top of stack : "<<vec.back()<<endl;
} 
bool Stack :: isEmpty(){
    if(vec.size() == 0) return true;
    else return false;
}
void Stack :: display_Data(){
    while(vec.size() != 0){
        cout<<vec.back()<<" ";
        vec.pop_back();
    }
  cout<<endl;
}
int Stack :: stack_Capacity(){
  return vec.capacity();
}
void stackOperation(){
    Stack s;
    int ch;
  while(1){
      cout<<"\nSelect an option : ";
      cin>>ch;
    if(ch == 1){
     int x;
     cout<<"Enter your data : ";
     cin>>x;
     s.push(x);
    }
        else if(ch == 2){
          s.pop();
    } else if(ch == 3){
       s.peek();
    } else if(ch == 4){
          s.display_Data();
     }else if(ch == 5){
       cout<<"The capacity of stack container = "<<s.stack_Capacity()<<endl;
     }else if(ch == 6){
       cout<<"Is stack is empty or not "<<s.isEmpty()<<endl;
     }
      else{
       cout<<"I hope you enjoy the Stack-operation game.\nVisit again"<<endl;
          return ;
    }
     }
  }

int main(){
  cout<<"Welcome to Stack data structure World !\n"<<endl;
  cout<<"Press-1 : To insert the data into the stack container\nPress-2 : To delete the data from the stack\nPress-3 : To check the value at top of stack\nPress-4 : To display the stack data\nPress-5 : To check capacity of stack container\nPress-6 : To check the stack is empty or not"<<endl;
  stackOperation();
  return 0;
}