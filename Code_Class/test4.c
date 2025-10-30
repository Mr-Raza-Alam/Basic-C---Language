#include<stdio.h>
void main (){
    int n ,i,t,bd,A[10];
    printf("Enter your decimal no. = ");
    scanf("%d",&n);
    for(i = 0; n>0; i++){
        A[i] = n%2;
        n = n/2;
    }
    t = i-1;
    printf("The decimal is converted into binary digits\n");
    for(i = t; i>=0; i--) printf("%d ",A[i]);

}