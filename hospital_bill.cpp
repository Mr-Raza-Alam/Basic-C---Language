#include<iostream>
#include<string>
using namespace std;
void outPatient();
void inPatient();
 static double tax = 0.20;
 class HospitalBill{
 private:
  int nDays,regCharge;
  string  roomType[3] = {"normal-ward","emergency-ward","waiting-room"};
  double consultingCharge,testCharge;
  public:
     HospitalBill(){
        nDays = 0;
        regCharge = 0;
        consultingCharge = 0.0;
        testCharge = 0.0;
     }
     HospitalBill(int d,int regC,double cc,double tc){
        this->nDays = d;
        this->regCharge = regC;
        this->consultingCharge = cc;
        this->testCharge = tc;
     }
    double inPatientBill(string room);
    double outPatientBill();
 };

 double HospitalBill :: inPatientBill(string room){
   if(room == this->roomType[0]){
    cout<<"Normal ward is accessed by the customer"<<endl;
    double charge = (consultingCharge + testCharge)*tax;
    cout<<"extra charge including tax of 20% : "<<charge<<endl;
    return ((this->consultingCharge + this->testCharge)*nDays + charge);// total bill of inpatient type
   }else if(room == this->roomType[1]){
    cout<<"Emergency ward is accessed by the customer. extra charge : 100"<<endl;
    double charge = (consultingCharge + testCharge)*tax;
    cout<<"extra charge including tax of 20% : "<<charge<<endl;
    return ((this->consultingCharge + this->testCharge )*nDays + 100 + charge);// total bill of inpatient type
   }else{
    cout<<room<<" is unavialable.choose only correct one."<<endl;
    return 0.0;
   }
 }
 double HospitalBill :: outPatientBill(){ 
     double charge = (testCharge + consultingCharge)*tax;
     cout<<" extra charge including tax of 20% : "<<charge<<endl;
     return (this->consultingCharge + this->testCharge + regCharge+charge);// total bill of outpatient type
  }

  void inPatient(){
    cout<<"Welcome to inPatient bill generator.\n"<<endl;
    string room;
    double concCharge,testC;
    int nDay;
    cout<<"Enter doctor consulting charge : ";
    cin>>concCharge;
    cout<<"Enter test charge : ";
    cin>>testC;
    cout<<"Enter the type of ward : ";
    cin>>room;
    cout<<"Enter the admitted days : ";
    cin>>nDay;
   HospitalBill h1(nDay,0,concCharge,testC); 
   cout<<"Total bill : "<<h1.inPatientBill(room)<<endl;
  }

  int main(){
    int ch;
    cout<<"Press-1 : to get inPatient's Bill.\nPress-2 : to get outPatient's Bill."<<endl;
    while(1){
      cout<<"\nEnter an option : ";
      cin>>ch;
      if(ch == 1){
        inPatient();
      }else if(ch == 2){
        outPatient();
      }else{
        cout<<"Oops! you entered a wrong option.try again."<<endl;
        break;
      }
    }
    return 0;
  }

  void outPatient(){
    cout<<"Welcome to outPatient bill generator.\n"<<endl;
    int regCharge;
    double testC,docCon;
    cout<<"Enter the registration charge  : ";
    cin>>regCharge;
    cout<<"Enter doctor consulting charge : ";
    cin>>docCon;
    cout<<"Enter test charge : ";
    cin>>testC;  
   HospitalBill h2(0,regCharge,docCon,testC);
   cout<<"Total bill : "<<h2.outPatientBill()<<endl;
  }
