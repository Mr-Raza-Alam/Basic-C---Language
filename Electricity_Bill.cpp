// Alam Electricity copt.ltd pvt.
#include<iostream>
#include<string>
using namespace std;
 
// ii)
class Electricity{
 public : 
 double electricityBill(){
   int eUnit;
   double bill;
 cout<<"\nRead the metere and mention the charge unit : ";
 cin>>eUnit;
// now apply condition to generate the bill
  if(eUnit>0 && eUnit<=300){
    // Rupees 2 per unit charge
     return (eUnit * 2);
   }else if(eUnit>300){
    return (eUnit*3);
   }
  }
};
// iii)
class moreEelectricity:public Electricity{// single inheritance
  public:
  void electBill(string name){
  // collect the bill from Electricity class
  Electricity e;
  double bill = e.electricityBill();
  if(bill<=250.00){
      // print the original bill
    cout<<name<<"\nYour electricity bill : "<<bill<<endl;
   }else{
    // then add subCharge of 15% to the original bill
    cout<<name<<"\nYour electricity bill : "<<(bill + bill*0.15)<<endl;
   }
  }
};

int main(){
  moreEelectricity e1;
  string name;
  cout<<"Enter the customer name : ";
  getline(cin,name);
  e1.electBill(name);
  //double bill = electricityBill();
  //cout<<"Mr. "<<name<<"\nYour electricity bill is : "<<bill<<endl;
  return 0;  
} 

// i)---> Generate Electricit Bill 
double electricityBill(){
   int eUnit;
   double bill;

 cout<<"\nRead the metere and mention the charge unit : ";
 cin>>eUnit;
// now apply condition to generate the bill
  if(eUnit>0 && eUnit<=300){
    // Rupees 2 per unit charge
    int totalbill = (eUnit * 2);
    if(totalbill<=250){
        return double(totalbill);
    }else{
      // add 15% subcharge-- totalbill + totalbill * 0.15
      return double(totalbill + totalbill*0.15);
    }
  }else if(eUnit>300){
    // Rupees 3 per unit charge
    int totalbill = (eUnit * 3);
    if(totalbill<=250){
        return double(totalbill);
    }else{
      // add 15% subcharge-- totalbill + totalbill * 0.15
      return double(totalbill + totalbill*0.15);
    }
  }
}