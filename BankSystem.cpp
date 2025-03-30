#include<iostream>
#include<string>
using namespace std;

class Bank;
class EmployeeInfo;

class Bank{
  private:
   double totalAmount = 0;
   string acc;
  public:
   void createAccount(string Acc_No){
      acc = Acc_No;
   } 
 public :
   void deposite(double amount){
     totalAmount = totalAmount + amount;
     cout<<amount<<" has been credit into the account no. "<<acc<<"\nTotal Balance "<<totalAmount<<endl;
   }
 public :
   void withdraw(double amount){
     if(amount <= totalAmount){
     totalAmount = totalAmount - amount;
     cout<<amount<<" has been debit from the account no. "<<acc<<"\nTotal Balance : "<<totalAmount<<endl;
     } else{
        cout<<"Insufficient Balance!"<<endl;
     }
   }
 public:
  double getAmount(){
     return totalAmount;
  } 
 public :
  string getAccount(){
    return acc;
  }
 public :
  void checkBalance(){
    cout<<"Your balance : "<<totalAmount<<endl;
  }
};

class EmployeeInfo{
  private:
    string name,email_id;
  public :
    void setInfo(string Name,string Email);
 public :
    int generateId(string Name,string email);
};
 void EmployeeInfo :: setInfo(string Name,string Email){
    name = Name;
    email_id = Email;
} 

int EmployeeInfo :: generateId(string Name,string email){
      int len = Name.length();
      int l = email.length();
      return (l/len);
}
void userService(int id);
void transaction(Bank account[]);
void bankEmployee(Bank account[],int Empid,int t);
int t;
void create(Bank account[],int i){
   t = i+1;
  string acc;
  cout<<"\nCreate your saving account  : ";
  cin>>acc;
  cout<<"\nYou have successfully created a saving account.\nHere is your Account-id : "<<(5-i)<<endl;
  account[i].createAccount(acc);
  cout<<"Check-out the following facility serves by us.\n"<<endl;
  cout<<"Press-1 :- To deposite an amount\nPress-2 :- To withdraw a desire amount\nPress-3 :- To check your balance"<<endl; 
  int ch;
  while(1){
    cout<<"\nSelect an option : " ;
    cin>>ch;
    if(ch == 1){
      double amt;
      cout<<"Enter the depoite amount : ";
      cin>>amt;
      account[i].deposite(amt);
    } else if(ch == 2){
      double wamt;
      cout<<"Enter the withdraw amount : ";
      cin>>wamt;
      account[i].withdraw(wamt);
    }else if(ch == 3){
      account[i].checkBalance();
    }
    else{
      cout<<"I hope,you experi nence well by our service.Visit again!"<<endl;
      return;
    }       
  }
}
 

void userService(int id){
  Bank account[3]; 
  int ch, i = -1;
  cout<<"Press-1 : To create a new account.\nPress-2 : for transaction process.\nPress-3 : for bank employee purpose"<<endl;
 while(1){
    cout<<"\nEnter the choice of action = ";
     cin>>ch;
    if(ch == 1){
        i++; 
      if(i>=0 && i<5){
        create(account,i);
       }else{
        cout<<"Error!,Wait for while,we are trying to extend our customer limitation.\nTry it after sometime."<<endl;
          return;  
       }
    }
    else if(ch == 2){
      transaction(account);
    } 
    else if(ch == 3){
       bankEmployee(account,id,t);
    }
    else{
     cout<<"Sorry!You select a wrong option.Try again."<<endl;
      return;
    }
  }
}



int main(){
 cout<<"SBI-LITE is looking a candidate for the manager post,to manage the workload of bank service\nEligible one please mention the following details\n "<<endl;
 EmployeeInfo e1;
 string n,em;
 cout<<"Enter your name : ";
 cin>>n;
 cout<<"Enter your email-id : ";
 cin>>em;
 e1.setInfo(n,em);
 int id = e1.generateId(n,em);
 cout<<"Congratulation!you have been hired for the manager-post\nHere is employee-id ["<<id<<"] for future work\n\nALERT** : Don't share your employee-id with anyone"<<endl;
 cout<<"-----For Customer Services-----\n"<<endl;

 userService(id);

  return 0;
}

void bankEmployee(Bank account[],int Empid,int t){
  cout<<"Hi! how may i help you?\nHere we have some options for you."<<endl;
  cout<<"\nPress-1 : to check your customer's details."<<endl;
  int c;
  while(1){
    cout<<"\nSelect your option : ";
    cin>>c;
    if(c == 1){
      cout<<"\nPlease verfiy your employeed-id"<<endl;
      int k;
      cout<<"Enter your id-No : ";
      cin>>k;
     if(k == Empid){     
      cout<<"\nHi,Mr.manager here this is your customer's details."<<endl;
      cout<<"Account     Balance"<<endl;
     for(int i = 0; i<t; i++){
      cout<<account[i].getAccount()<<"    "<<account[i].getAmount()<<endl;
     }
     cout<<"\nHope you find well.Thank you have a nice day"<<endl; 
    } else{
      cout<<"Invalid employee-id."<<endl;
    }
  } else{
      cout<<"Sorry! You eneterd a wrong option. Try again after sometime."<<endl;
      return;
    }
  }
}

void transaction(Bank account[]){
  int i,j;
  string a,b;
  cout<<"Enter account no. of payment issuer with account-id : ";
  cin>>a;
  cin>>i;
  cout<<"Enter account no. of payment receiver with account-id :";
  cin>>b;
  cin>>j;
  if(account[5-i].getAccount() == a && account[5-j].getAccount() == b){
    cout<<"Successfully Verified!\nCan proceed the transaction process."<<endl;
    double Tamt;
    cout<<"Enter the transaction amount : ";
    cin>>Tamt;
    if(Tamt <= account[5-i].getAmount()){
       account[5-i].withdraw(Tamt);
       account[5-j].deposite(Tamt);
       cout<<"Successfully transaction process has been completed."<<endl;
    } else{
      cout<<"Insufficient Balance in account no. "<<a<<"\nPlease maintain a minimal balance for transaction\nThank-you have a nice day"<<endl;
    }
  }else{
    cout<<"Sorry for inconvenient issue.We could not fetch your account No.\nMake sure your entered exiting account No.\nIf there is no any account first create your account then procced transaction process."<<endl;
  }
}
