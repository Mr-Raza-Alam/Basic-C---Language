// 1stly we invoke preprocessesor of iostream 
#include<iostream>
#include<string>
// there is many different iostream is avialable in the linker but for our learning it require standard one i.e std
using namespace std;

class Employee{
private:
     string name,id;
     double salary;
 public :
     void setEmploy_Name(string name);
  public :
    void  setEmploy_Id(string id);
  public :
     void setEmploy_Salary(double sal);
     public :
      double getTotal_Salary(double sal);
 }; 

 void Employee :: setEmploy_Id(string id){
    id = id;
 }
 void Employee :: setEmploy_Name(string Name){
    name = Name;
 }
 void Employee :: setEmploy_Salary(double sal){
    salary = sal;
 }
 double Employee :: getTotal_Salary(double sal){
     return (sal + (sal*0.12));
 }
int main(){
    string s,str;
    double sal;
    Employee e1;
    cout<<"Enter your name : ";
    cin>>str;
    cout<<"Enter your id : ";
    cin>>s;
    cout<<"Enter your salary : ";
    cin>>sal;
    e1.setEmploy_Name(str);
    e1.setEmploy_Id(s);
    e1.setEmploy_Salary(sal);
    cout<<"\nYour information are given below :-"<<endl;
    cout<<"Employ name : "<<str<<endl;
    cout<<"Employ id : "<<s<<endl;
    cout<<"Employ base-salary : $"<<sal<<endl;
    cout<<"Employ total salary : $"<<e1.getTotal_Salary(sal)<<endl;
    return 0;
}
