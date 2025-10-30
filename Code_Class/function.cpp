 #include<iostream>
 using namespace std;
 int fact(int a ){
    if(a==1) return 1;
    return a*fact(a-1);
 }
 int nCr(int p,int q){
    return fact(p)/(fact(p-q)*fact(q)) ;
 }
 int main (){
  int n,i =1, s = 0,r;
  cout<<"Enter the total no. of items given = ";
  cin>>n;
  cout<<"Enter the no. of item wants to be choose = ";
  cin>>r;
  cout<<"The value of "<< n <<"C"<< r <<" = "<< nCr(n,r)<<endl;
  /*p = n;
  while(p>0){
    s += p%10;
    p /=10;
    i++;
  }
  cout<<"The sum of digits of "<<n<<" = "<<s<<endl;*/
  /*while(i>0){
    if(i==n) cout<<i;
    else cout<<" * "<<i;
    i--;
  }*/
  //cout<<" = "<< fact(n,p)<<endl;

    return 0; 
 }