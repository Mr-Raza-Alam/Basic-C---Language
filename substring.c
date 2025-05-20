#include<stdio.h>
#include<stdbool.h>
void checksub(int r,char str[r+5],char*p){
   bool flag = false;
   int i = 0,t = 0;
   while(str[i]!='\0'){
    if(str[i]==(*p)){
        flag = true;
        p++;
        t++;  
    }
    else flag = false;
    i++;
   }
   if(flag==true){
     printf("The given sub-string is exists in the string\n");
     printf("The length of given sub-string = %d\n",t);
   }
   else printf("The given sub-string is not exists in the string\n");
 
   return;
}
void main (){
  char str[50];
  printf("Enter your desire string :-\n");
  scanf("%[^\n]s",str);
  int i = 0,l = 0,t;
  while(str[i]!='\0'){
    l++;    
    i++;
  }
  printf("The length of given string = %d\n",l);
  char substr[l];
  printf("Enter your desire sub-string :-\n");
  scanf("%s",&substr);
   checksub(l,str,substr);

}