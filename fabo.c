#include<stdio.h>
int fabona(int m,int s){
    if(m==1 || m==2) return 1;
    return  fabona(m-1) + fabona(m-2);
    
}
void main (){
int n ;
printf("Enter the no. of fabonacci terms require = ");
scanf("%d",&n);
//printf("The sum of %d fabonacci series = %d\n",fabona(n,0));
printf("%dth fabonacci term = %d\n ",n,fabona(n,0));
}