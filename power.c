#include<stdio.h>
void power(int n, int m){
    int t =1,i =1;
    while(i<=m){
        t *=n;
        i++;  
    }
    printf("The value of %d to the power %d = %d\n",n,m,t);
    return ;
}
void main (){
    int a,b;
    printf("Enter your favourite no. = ");
    scanf("%d",&a);
    printf("Enter the power value raised to given no. = ");
    scanf("%d",&b);
    power(a,b);
}