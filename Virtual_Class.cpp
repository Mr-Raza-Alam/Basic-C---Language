#include<iostream>
#include<string>
using namespace std;

class student{
 protected:
  int roll_no;
  string name,dept;
 public:
   void setInfo(int roll,string n,string d);
   void getInfo();
};

 void student :: setInfo(int roll,string n,string d){
     roll_no = roll;
     name = n;
     dept = d;
 }

 void student :: getInfo(){
    cout<<"Student-Name : "<<name<<endl;
    cout<<"Student-department : "<<dept<<endl;
    cout<<"Student-roll_No : "<<roll_no<<endl;
 }
 
 class test : virtual public student{// hierarchical inheritance
   protected:
    float part1,part2;
    public:
     void setMarks(float x,float y);
     void getMarks();   
 };

 void test :: setMarks(float x,float y){
    part1 = x;
    part2 = y;
 }
 void test :: getMarks(){
   cout<<"Student-Marks : "<<endl;
   cout<<"Subject-1 : "<<part1<<endl;
   cout<<"Subject-2 : "<<part2<<endl;
 }

 class sports : virtual public student{// hierarchical inheritance
  protected:
    int score;// score -- sports's medals;
   public:
    void setScore(int s);
    void getScore();    
 };

 void sports :: setScore(int s){
    score = s;
 }
 void sports :: getScore(){
   cout<<"Sports-Score : "<<score<<endl;
 }

 class result : public test,public sports{// hybrid inheritance
   public:
    void display();
 };
 void result :: display(){
   cout<<"The result of virtual class is : "<<endl;
    int total = part1 + part2 + score;
    getInfo();
    getMarks();
    getScore();
    cout<<"Total Score : "<<total<<endl;
    cout<<"Hurray! hybrid inheritance is working well"<<endl;                     
 }

 int main(){
    result r;
    int roll,s;
    float x,y;
    string n,d;
    cout<<"Enter name : ";
    cin>>n;
    cout<<"Enter department : ";
    cin>>d;
    cout<<"Enter roll no : ";
    cin>>roll;
    cout<<"Enter mark of subject-1 : ";
    cin>>x;
    cout<<"Enter mark of subject-2 : ";
    cin>>y;
    cout<<"Enter score of sport : ";
    cin>>s;
    r.setInfo(roll,n,d);
    r.setMarks(x,y);
    r.setScore(s);
    r.display();
   return 0;
 }